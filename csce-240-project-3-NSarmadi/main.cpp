#include <iostream>
#include "./ArrayList.cpp"

int main(int argc, char **argv) {
  
  // ------------Testing Operator!=-----------------
  ArrayList<int> a(2,1), b(3,1);
  std::cout << "----\nTesting operator!= \n";
  std::cout << "Your output: \n";
  bool test = (a != b); 
  std::cout << test << "\n"; 
  std::cout << "Correct output: \n1\n";
  
  std::cout << "----\nTesting operator!= \n";
  std::cout << "Your output: \n";
  test = (a != a); 
  std::cout << test << "\n"; 
  std::cout << "Correct output: \n0\n";
  
  // ------------Testing Operator+(T)-----------------
  ArrayList<int> c(2,1), c_ret; 
  ArrayList<char> d, d_ret;
  std::cout << "----\nTesting operator+(T) \n";
  std::cout << "Your output: \n";
  c_ret = c + 2;
  std::cout << "c: " << c << " c_ret: " << c_ret << "\n"; 
  std::cout << "Correct output: \nc: [1 1] c_ret: [3 3] \n";
  
  std::cout << "----\nTesting operator+(T) \n";
  std::cout << "Your output: \n";
  d_ret = d + 'a';
  std::cout << "d: " << d << " d_ret: " << d_ret << "\n"; 
  std::cout << "Correct output: \nd: [] d_ret: [] \n";
  
  
  // ------------Testing Operator+(ArrayList<T>)-----------------
  ArrayList<int> e(2,1), e2(2,2), e_ret; 
  ArrayList<char> f, f2(1,'a'), f_ret;
  std::cout << "----\nTesting operator+(ArrayList<T>) \n";
  std::cout << "Your output: \n";
  e_ret = e + e2;
  std::cout << "e: " << e << " e2: " << e2 << " e_ret: " << e_ret << "\n"; 
  std::cout << "Correct output: \ne: [1 1] e2: [2 2] e_ret: [3 3] \n";
  
  std::cout << "----\nTesting operator+(ArrayList<T>) \n";
  std::cout << "Your output: \n";
  f_ret = f + f2;
  std::cout << "f: " << f << " f2: " << f2 << " f_ret: " << f_ret << "\n"; 
  std::cout << "Correct output: \nf: [] f2: [a] f_ret: [] \n";
  
  // ------------Testing Operator--()-----------------
  ArrayList<int> g(2,1), g_ret;
  g[1] = 2; 
  ArrayList<char> h, h_ret;
  std::cout << "----\nTesting operator--() \n";
  std::cout << "Your output: \n";
  g_ret = --g;
  std::cout << "g: " << g << " g_ret: " << g_ret << "\n"; 
  std::cout << "Correct output: \ng: [1] g_ret: [1] \n";
  
  std::cout << "----\nTesting operator--() \n";
  std::cout << "Your output: \n";
  h_ret = --h;
  std::cout << "h: " << h << " h_ret: " << h_ret << "\n"; 
  std::cout << "Correct output: \nh: [] h_ret: [] \n";
  
  // ------------Testing Operator--(int)-----------------
  ArrayList<int> i(2,1), i_ret;
  ArrayList<char> j, j_ret;
  std::cout << "----\nTesting operator--(int) \n";
  std::cout << "Your output: \n";
  i_ret = i--;
  std::cout << "i: " << i << " i_ret: " << i_ret << "\n"; 
  std::cout << "Correct output: \ni: [1] i_ret: [1 1] \n";
  
  std::cout << "----\nTesting operator--(int) \n";
  std::cout << "Your output: \n";
  j_ret = j--;
  std::cout << "j: " << j << " j_ret: " << j_ret << "\n"; 
  std::cout << "Correct output: \nj: [] j_ret: [] \n";
  
  // ------------Testing Operator+=(T)-----------------
  ArrayList<int> k(2,1);
  ArrayList<char> l;
  std::cout << "----\nTesting operator+=(T) \n";
  std::cout << "Your output: \n";
  k+=2;
  std::cout << "k: " << k<< "\n"; 
  std::cout << "Correct output: \nk: [1 1 2] \n";
  
  std::cout << "----\nTesting operator+=(T) \n";
  std::cout << "Your output: \n";
  l+='a';
  std::cout << "l: " << l<< "\n"; 
  std::cout << "Correct output: \nl: [a] \n";
  
  // ------------Testing Operator+=(ArrayList<T>)-----------------
  ArrayList<int> m(2,1), m2(3,2);
  ArrayList<char> n, n2(1,'a');
  std::cout << "----\nTesting operator+=(ArrayList<T>) \n";
  std::cout << "Your output: \n";
  m+=m2;
  std::cout << "m: " << m << " m2: " << m2 << "\n"; 
  std::cout << "Correct output: \nm: [1 1 2 2 2] m2: [2 2 2] \n";
  
  std::cout << "----\nTesting operator+=(ArrayList<T>) \n";
  std::cout << "Your output: \n";
  n+=n2;
  std::cout << "n: " << n << " n2: " << n2 << "\n"; 
  std::cout << "Correct output: \nn: [a] n2: [a] \n";
  
  // ------------Testing Operator*(int)-----------------
  ArrayList<int> o(2,1), o_ret;
  ArrayList<char> p, p_ret;
  std::cout << "----\nTesting operator*(int) \n";
  std::cout << "Your output: \n";
  o_ret = o*2;
  std::cout << "o: " << o << " o_ret: " << o_ret << "\n"; 
  std::cout << "Correct output: \no: [1 1] o_ret: [1 1 1 1] \n";
  
  std::cout << "----\nTesting operator*(int) \n";
  std::cout << "Your output: \n";
  p_ret = p*2;
  std::cout << "p: " << p << " p_ret: " << p_ret << "\n"; 
  std::cout << "Correct output: \np: [] p_ret: [] \n";
  
  // ------------Testing Operator/(int)-----------------
  ArrayList<int> q(5,1), q_ret;
  ArrayList<char> r, r_ret;
  std::cout << "----\nTesting operator/(int) \n";
  std::cout << "Your output: \n";
  q_ret = q/2;
  std::cout << "q: " << q << " q_ret: " << q_ret << "\n"; 
  std::cout << "Correct output: \nq: [1 1 1 1 1] q_ret: [1 1] \n";
  
  std::cout << "----\nTesting operator/(int) \n";
  std::cout << "Your output: \n";
  r_ret = r/2;
  std::cout << "r: " << r << " r_ret: " << r_ret << "\n"; 
  std::cout << "Correct output: \nr: [] r_ret: [] \n";
  
  return 0; 
}
