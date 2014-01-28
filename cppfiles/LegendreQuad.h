#ifndef LEGQUAD
#define LEGQUAD

#define MATSIZE 20

class LegendreQuad{
private:
	int nSize;
public:
	//~ int LegendreQuad(int);
	int setElementSize(int value);
  int getElementSize();
	void MakeTmatrix();
  double getCollocation(int n);
  double getWeight(int n);
  void setCollocation(double val,int n);
  void setWeight(double val,int n);


protected:

private:

  double x[MATSIZE];
  double w[MATSIZE];

};


#endif
