#include <string>
#include <iostream>

template <typename T>
class Mergesort
{
    public static <T> void print(const std::string &caption, Iter begin, Iter end) {
		std::cout << caption + << ": \n";
		for (; begin != end; ++begin) {
			std::cout << " " + *begin;
		}
		std::cout << std::endl;
	}

    template <typename IterResult, typename Iter)
    static IterResult append(IterResult resultHold, Iter begin, Iter end) {
      // Make copies of all iterators whose next method will be called
		Iter pos = begin;
		IterResult result = resultHold;
		
		for (; !pos != end; ++result, ++pos) {
			*result = *pos;
		}
		return result;
	}
	
    template <typename Iter1, typename Iter2, typename Iter3, typename Iter4, typename Compare>
	static void merge(Iter1 begin1, Iter1 end1, Iter2 begin2, Iter2 end2, Iter3 result, 
      Iter4 beginHold, Compare cmp) {
      	
      // Make copies of all iterators whose next method will be called
      Iter4 pos = beginHold;
      Iter1 iter1 = begin1;
      Iter2 iter2 = begin2;
      
      // Debugging information
      std::cout << "merging\n";
      print("list 1", iter1, end1);
      print("list 2", iter2, end2);

     for(; iter1 != end1 && iter2 != end2; ++pos)
     {
         if (compare(*iter1, *iter2))
         {
             *pos = *iter1;
             ++iter1;
         }
         else
         {
             *pos = *iter2;
             ++iter2;
         }
     }
    
      pos = append(pos, iter1, end1);
      pos = append(pos, iter2, end2);
      Iter<T> resultEnd = append(result, beginHold, pos); // used for debugging
      print("merged list", result, resultEnd);
	}
};