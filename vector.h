#include <iostream>
class vector
{
public:
  vector();
  ~vector();
  vector(const vector &copy);
  void operator = (const vector &copy);
  void push_back(int elem);
  void insert_at(int index, int elem);
  int get_at(int index);
  int get_size();
  
private:
  int* m_arr;
  int  m_size;
};