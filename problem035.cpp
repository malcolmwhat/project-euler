#include <iostream>
#include <vector>
#include <algorithm>

void print_vector(std::vector<int> v);
bool set_contains(int n, std::vector<int> set);
std::vector<int> circular_permutations(int n);
std::vector<int> int_to_vector(int n);
int digit_count(int n);

/*
 * The problem is the following:
 * The number 197, is called a circular prime because all rotations of the
 * digits: 197, 971, and 719 are themselves prime.
 *
 * There are thirteen such primes below 100: 2,3,5,7,11,13,17,31,37,71,73,79&97.
 *
 * How many circular primes are there below one million?
 */

/*
 * This class' primary purpose is to allow the user to easily find all
 * the primes within a certain range.
 */
class Primes
{
    // task specific struct
    struct value
    {
      bool checked;
      bool prime;
      int num;
    };

    // fields
    std::vector<int> primes;
    int index;
    std::vector<value> set;
    int upper_lim;

    // methods
    std::vector<value> initialize_set(int upper_bound);
    int next_prime();
    void mark_multiples_of(int n) {
      for (int i = n;  i <= upper_lim;  i+=n) {
        set.at(i).checked = true;
      }
    }

  public:
    std::vector<int> get_upto(int upper_bound);
};


/*
 * Returns a vector of all the primes up to upper_bound
 */
std::vector<int> Primes::get_upto(int upper_bound)
{
  upper_lim = upper_bound;
  set = initialize_set(upper_bound);

  int prime = next_prime();
  while (prime != -1){
    mark_multiples_of(prime);
    prime = next_prime();
  }

  return primes;
}


/*
 * Get the index of the next prime, tag it, and add it to the primes vector
 */
 int Primes::next_prime()
 {
   int i = index;

   while (i < upper_lim) {
     Primes::value elem = set.at(i);
     if (elem.checked == false){
       primes.push_back(i);
       elem.checked = true;
       elem.prime = false;
       index = i;
       return i;
     }
     ++i;
   }

   return -1;
 }


/*
 * Creates a simple vector of structs from 0 to upper_bound
 */
std::vector<Primes::value> Primes::initialize_set(int upper_bound)
{
  index = 1;
  std::vector<Primes::value> nums;
  for (int i = 0; i <= upper_bound; i++) {
    Primes::value temp;
    temp.checked = i < 2;
    temp.prime = false;
    temp.num = i;
    nums.push_back(temp);
  }
  return nums;
}


/*
 * The main purpose of this class is to allow the user to find all circular
 * primes within a certain range.
 */
class Circular: public Primes
{
    struct value{
      bool checked;
      int num;
    };

    struct digit_range
    {
      int digits;
      int starting_index;
    };

    std::vector<value> check_set(std::vector<int> set);
    std::vector<digit_range> get_ranges(std::vector<int> set);

  public:
    std::vector<int> get_upto(int n);
};


/*
 * Gets all the circular_primes upto n. See inline comments for details.
 */
std::vector<int> Circular::get_upto(int n)
{
  using namespace std;
  vector<int> initial_set = Primes::get_upto(n);
  vector<int> circular_primes;

  // change the format of our set to structs which we can tag as checked
  vector<Circular::value> set = check_set(initial_set);

  // vector indicating when the 1 digit, 2 digit, 3 digit, etc numbers start
  vector<Circular::digit_range> rn = get_ranges(initial_set);

  for(unsigned int i = 0; i < rn.size(); i++){
    // for each of the digit ranges
    int digits = rn.at(i).digits;
    int starting_index = rn.at(i).starting_index;

    unsigned int index = starting_index;

    // while we're in the current range
    while(index < set.size() && digit_count(set.at(index).num) == digits)
    {
      // if we've seen it already
      if(set.at(index).checked)
      {
        ++index;
      }
      else
      {
        int prime = set.at(index).num;

        // get the circular permutations of the current prime
        vector<int> permutations = circular_permutations(prime);

        unsigned int intermediate = index;
        vector<int>::iterator it = permutations.begin();

        // effectively check that every permutation is in the primes set
        while(intermediate < set.size() && digit_count(set.at(intermediate).num) == digits)
        {
          // if the number in the primes set is the next value of the permutation
          if(set.at(intermediate).num == *it)
          {
            set.at(intermediate).checked = true;
            ++it;

            // if this is the last value of the permutation then all of the permutations are circular
            if(it == permutations.end())
            {
              // add them all to the circular_primes vector
              for(vector<int>::iterator itt = permutations.begin(); itt != permutations.end(); ++itt)
              {
                circular_primes.push_back(*itt);
              }
              break; // break the inner while loop
            }
          }
          else if(set.at(intermediate).num > *it)
          {
            break; // There is a missing permutation
          }
          ++intermediate;
        }
        ++index;
      }
    }
  }
  return circular_primes;
}


/*
 * true if n is in set, false otherwise
 */
bool set_contains(int n, std::vector<int> set)
{
  using namespace std;
  for(vector<int>::iterator it = set.begin(); it != set.end(); ++it)
  {
    if (n == *it)
    {
      return true;
    }
  }
  return false;
}


std::vector<Circular::digit_range> Circular::get_ranges(std::vector<int> set)
{
  using namespace std;

  vector<Circular::digit_range> rn;
  int prev_count = 0;
  for(unsigned int i = 0; i < set.size(); ++i)
  {
    int current_count = digit_count(set.at(i));
    if(current_count != prev_count)
    {
      Circular::digit_range temp;
      temp.digits = current_count;
      temp.starting_index = i;
      rn.push_back(temp);
      prev_count = current_count;
    }
  }

  return rn;
}


std::vector<Circular::value> Circular::check_set(std::vector<int> set)
{
  using namespace std;
  vector<Circular::value> values;

  vector<int>::iterator it = set.begin();
  for(; it != set.end(); ++it)
  {
    Circular::value temp;
    temp.checked = false;
    temp.num = *it;
    values.push_back(temp);
  }

  return values;
}


// self explanatory
std::vector<int> add_if_unique(int n, std::vector<int> set)
{
  using namespace std;
  for(vector<int>::iterator it = set.begin(); it != set.end(); ++it)
  {
    if (n == *it)
    {
      return set;
    }
  }
  set.push_back(n);
  return set;
}


std::vector<int> int_to_vector(int n)
{
  using namespace std;
  vector<int> result;
  do {
    result.push_back(n % 10);
    n /= 10;
  } while(n);
  std::reverse(result.begin(), result.end());
  return result;
}


int vector_to_int(std::vector<int> value)
{
  using namespace std;
  int n = 0;
  for(vector<int>::iterator it = value.begin(); it != value.end(); ++it)
  {
    n = 10 * n + *it;
  }
  return n;
}


std::vector<int> circular_permutations(int n)
{
  using namespace std;

  vector<int> permutations;
  vector<int> vect_rep = int_to_vector(n);

  for(int i = 0; i < digit_count(n); i++)
  {
    permutations = add_if_unique(vector_to_int(vect_rep), permutations);

    vect_rep.push_back(vect_rep.at(0));
    vect_rep.erase(vect_rep.begin());
  }

  sort(permutations.begin(), permutations.end());
  return permutations;
}


void print_vector(std::vector<int> v)
{
  for(unsigned int i = 0; i < v.size(); i++)
  {
    std::cout << v.at(i) << ", ";
  }
  std::cout << std::endl;
}

void print_permutations_of(int n)
{
  std::vector<int> permutations = circular_permutations(n);
  std::cout << "The permutations of " << n << " are:" << std::endl;

  for(unsigned int i = 0; i < permutations.size(); i++)
  {
    std::cout << permutations.at(i) << std::endl;
  }
  std::cout << "-------------------" << std::endl;
}


int digit_count(int n)
{
  int count = 0;
  do {
    ++count;
    n /= 10;
  } while(n);
  return count;
}


int main(int argc, char const *argv[]) {
  Circular a;
  std::vector<int> v = a.get_upto(1000000);
  std::cout << "--------------------------" << std::endl;
  std::cout << "Number of circular primes: " << v.size() << std::endl;
  std::cout << "--------------------------" << std::endl;
  return 0;
}
