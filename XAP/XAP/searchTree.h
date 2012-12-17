using namespace System::Collections::Generic;
namespace	Monitor4vc{
	ref class searchTree{
	private:
		ref class treeNode{
		private:
			char val;
			int response;
			LinkedList<treeNode ^> entries;
		
			treeNode ^getNext(char c){
				for each(treeNode ^t in entries){
					if(t->getC()==c)return t;
				}
				return nullptr;
			}
		public:
			int containsStr(char *check){
				if(strlen(check)==0) return response;
				treeNode ^n=getNext(check[0]);
				if(n==nullptr)return -1;
				check++;
				return n->containsStr(check);

			}

			void addVal(char *c, int i){
				if(strlen(c)==0){
					response=i;
					return;
				}
				for each(treeNode ^t in entries){
					if(t->getC()==c[0]){
						c++;
						t->addVal(c, i);
						return;
					}
				}
				treeNode ^n;
				n->setC(c[0]);
				entries.AddLast(n);
				c++;
				n->addVal(c,i);
				
			}

			char getC(){
				return val;
			}

			int getR(){
				return response;
			}

			void setC(char c){
				val=c;
			}

			void setR(int r){
				response=r;
			}

			void clear(){
				entries.Clear();
			}
		};
		
		treeNode ^tree;
		
		void addWord(char *c, int v){
			tree->addVal(c,v);
		}

		int checkStr(char *check){
			while(strlen(check)>0){
				char *c=check;
				int r=tree->containsStr(c);
				if(r!=-1)return r;
				check++;
			}
			return -1;
		}

		void zeroTree(){
			tree->clear();
		}


	};

}