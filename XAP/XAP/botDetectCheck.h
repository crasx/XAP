namespace XAP {
	ref class botDetectCheck{
	private:
		ref struct botE{
			array<playerCoordinates ^> ^coords;
		};
		ref struct avg{
			double average;
			int count;
			tsint bots;
		};
		tsbool quit, debug, newgame;

		Thread^ botT;
		commandSender ^rcon;
		Object ^aro;

		System::Collections::Generic::Queue<Hashtable ^> ^botStack;
		Hashtable/*<playerCoordinates ^>*/ ^hold;
		Hashtable/*<avg ^>*/ ^average;
	public:
		void setRcon(commandSender ^r){
			rcon=r;
		}

		void newGame(){
			if(quit.get())return;
			if(botT!=nullptr){
				quit.set(true);
				while(botT->IsAlive)Sleep(10);
				quit.set(false);
			}
			average=gcnew Hashtable();
			hold=gcnew Hashtable();
			botT = gcnew Thread(gcnew ThreadStart(this, &botDetectCheck::checkBot));
			botT->Start();

		}

		void playerQuit(int i){
			Monitor::Enter(aro);
			if(!average->ContainsKey(i*2))return;
			average->Remove(i*2);
			Monitor::Exit(aro);
			
		}

		int getBot(int i){
			if(!average->ContainsKey(i*2))return 0;
			
			int r= ((avg ^)average[i*2])->bots.get();
			((avg ^)average[i*2])->bots.set(0);
			return r;

		}

		botDetectCheck(void){
			quit.set(false);
			aro=gcnew Object();
			hold=gcnew Hashtable();
			average=gcnew Hashtable();
			botStack=gcnew System::Collections::Generic::Queue<Hashtable ^>();
		}
		void Debug(){

			debug.set(true);
		}
		void Quit(){
			quit.set(true);
		}

		void addCoords(playerCoordinates ^val, int id){
			Monitor::Enter(aro);
			if(!hold->ContainsKey(id)){
				hold->Add(id, val);
			}else{
				Monitor::Enter(botStack);
				botStack->Enqueue(hold);
				Monitor::Exit(botStack);
				hold=gcnew Hashtable();
			}			
			Monitor::Exit(aro);
		}

		void checkBot(){
			Hashtable ^newL, ^old;

			int maxAverage=32;
			bool oldW=false, loop=false;
			for(;;){
				if(quit.get())return;
				Monitor::Enter(botStack);
				if(botStack->Count!=0){
					if(oldW){
						newL=botStack->Dequeue();
						Monitor::Exit(botStack);
						try{
						for each(int key in newL->Keys){
							if(old[key]==nullptr||newL[key]==nullptr)goto skipAvg;
							float xc=Math::Abs(((playerCoordinates ^)newL[key])->xv-((playerCoordinates ^)old[key])->xv);
							float yc=Math::Abs(((playerCoordinates ^)newL[key])->yv-((playerCoordinates ^)old[key])->yv);
							float zc=Math::Abs(((playerCoordinates ^)newL[key])->zv-((playerCoordinates ^)old[key])->zv);
							float oc=Math::Sqrt(xc*xc+yc*yc+zc*zc);
							avg ^avgH=(avg ^)average[key];
							if(avgH==nullptr){
								avgH=gcnew avg();
								goto skipAvg;
							}
							if(debug.get()){
							//	rcon->addCmd("sv_say \"Debug "+key+" "+avgH->average+" "+oc+" "+avgH->bots.get()+" "+((playerCoordinates ^)newL[key])->name+" "+((playerCoordinates ^)newL[key])->uid+"\"");
								loop=true;
							}

							if(avgH->count>0&&oc>0&&oc<20){
								double mac=(avgH->count)*avgH->average;
								mac+=oc;
								if(avgH->average*7<oc&&avgH->count==maxAverage){						
									for each(int okey in newL->Keys){
										if(okey==key)continue;
										if(((playerCoordinates ^)newL[key])->tid==((playerCoordinates ^)newL[okey])->tid)continue;
										
										bool xbm=((playerCoordinates ^)newL[key])->x>((playerCoordinates ^)newL[key])->xv;
										if(xbm!=(((playerCoordinates ^)newL[okey])->x>((playerCoordinates ^)newL[key])->x))continue;
										
										bool ybm=((playerCoordinates ^)newL[key])->y>((playerCoordinates ^)newL[key])->yv;
										if(ybm!=(((playerCoordinates ^)newL[okey])->y>((playerCoordinates ^)newL[key])->y))continue;
										
										bool zbm=((playerCoordinates ^)newL[key])->z>((playerCoordinates ^)newL[key])->zv;
										if(zbm!=(((playerCoordinates ^)newL[okey])->z>((playerCoordinates ^)newL[key])->z))continue;
										try{
										float md1=((playerCoordinates ^)newL[key])->yv/((playerCoordinates ^)newL[key])->xv;
										float md2=((playerCoordinates ^)newL[okey])->yv/((playerCoordinates ^)newL[okey])->xv;
							
										float b1=((playerCoordinates ^)newL[key])->y-(md1*((playerCoordinates ^)newL[key])->x);
										float b2=((playerCoordinates ^)newL[okey])->y-(md2*((playerCoordinates ^)newL[okey])->x);

										float collision=(b2-b1)/(md2-md1);
										Debug::WriteLine(collision);
										}catch(Exception ^ex){

										}
									}
								//	rcon->addCmd("sv_say \"Bot "+i+" "+avgH->average+" "+oc+"\"");
									avgH->bots.increment();
								}
								if(avgH->count<maxAverage)avgH->count++;
								else mac-=avgH->average;
								avgH->average=mac/avgH->count;
							}else if(oc>0&&oc<20){
								avgH->average=oc;
								avgH->count++;
							}
skipAvg:
							average[key]=avgH;
							//		if(xc>.5||yc>.5||zc>.5){
							old=newL;

						}
						}catch(Exception ^ex){}

					}
					else{
						Monitor::Exit(botStack);
						old=botStack->Dequeue();
						oldW=true;
					}
				}else{
					Monitor::Exit(botStack);
					Sleep(20);
				}
				Sleep(5);
				if(debug.get()){
					if(loop){

						Monitor::Enter(botStack);
						rcon->addCmd("sv_say \"stack size- "+botStack->Count+"\"");

						Monitor::Exit(botStack);
						debug.set(false);
						loop=false;
					}
				}

			}
		}


		/*
		int prev=players[inx]->curpos.get()-1;
		if(prev==-1)prev=players[inx]->coordinates->Length-1;
		float xc=players[inx]->coordinates[prev]->xv>pobj.xv?players[inx]->coordinates[prev]->xv-pobj.xv:pobj.xv-players[inx]->coordinates[prev]->xv;
		float yc=players[inx]->coordinates[prev]->yv>pobj.yv?players[inx]->coordinates[prev]->yv-pobj.yv:pobj.yv-players[inx]->coordinates[prev]->yv;
		float zc=players[inx]->coordinates[prev]->zv>pobj.zv?players[inx]->coordinates[prev]->zv-pobj.zv:pobj.zv-players[inx]->coordinates[prev]->zv;

		players[inx]->coordinates[players[inx]->curpos.get()]=coord;
		players[inx]->curpos.increment();
		if(players[inx]->curpos.get()>=players[inx]->coordinates->Length)players[inx]->curpos.set(0);
		if(xc>.5||yc>.5||zc>.5){

		}
		*/

	};
}