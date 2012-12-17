namespace XAP {
	ref struct langS{
		String ^name;



	};

	ref class language{
	protected:
		langS ^translation;
	public:
		langS ^GET(){
			return translation;
		}
	};

	ref class english:language{

		english(){
			translation->name="XAP";
		}
	};
}