#ifndef LEGQUAD
#define LEGQUAD

#define MATSIZE 20

class LegendreQuad{
	
	private:
		int nSize;
		double x[MATSIZE];
		double w[MATSIZE];
	public:
		int setElementSize(int value);
		int getElementSize();
		void Eigs();
		double getCollocation(int n);
		double getWeight(int n);
		void setCollocation(double val,int n);
		void setWeight(double val,int n);
	protected:
};


#endif
