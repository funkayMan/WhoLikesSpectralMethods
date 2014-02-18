#ifndef GOO
#define GOO

class goo{
public:

  goo(int initial=0); // The constructor for the class.
  ~goo(void);         // The destructor for the class

  void setMyPrecious(int val); // Routine to set the value of my precious.
  int getMyPrecious();         // Routine to get the value of my precious

protected:
  int myPrecious;    // The value of my precious.

};

#endif
