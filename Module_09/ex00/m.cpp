// map::lower_bound/upper_bound
#include <iostream>
#include <map>

int main ()
{
  std::map<char,int> mymap;
  std::map<char,int>::iterator itlow,itup;

  mymap['a']=20;
  mymap['b']=40;
  mymap['c']=60;
  mymap['f']=80;
  mymap['s']=100;

  itlow=mymap.lower_bound ('h');  // itlow points to b
  itup=mymap.upper_bound ('h');   // itup points to e (not d!)

  mymap.erase(itlow,itup);        // erases [itlow,itup)

  // print content:
    std::cout << itlow->first << " => " << itlow->second << '\n';
	std::cout << itup->first << " => " << itup->second << '\n';
  //for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)

  return 0;
}