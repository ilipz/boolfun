#pragma once

#include "bitslib.h"
#include <vector>

namespace bf
{
  class GF
  {
  protected:
      int gen_el_found = 0;//� ���� ������ ���������� ��������� ��� �������, ������� ����� �����, ����� ����� ������������ �������
      unsigned int true_order;//������� ����, �� ������� ������, � 2^n
	  bvect32 field_polynom;
	  bvect32 gen_el;
	  std::vector<bvect32> num_to_deg;//������ ����������� ����� - ������� ������������� ��������
      std::vector<bvect32> deg_to_num;//������ ����������� ������� ������������ �������� - �����
	  unsigned char order;
	  virtual bvect32 mod(bvect64) = 0;
	  virtual bvect32 get_generating_element() = 0;
  public:
      virtual bvect32 sum(bvect32, bvect32) = 0;
	  virtual bvect32 multiply(bvect32, bvect32) = 0;
	  virtual bvect32 power(bvect32, bvect32) = 0;
	  virtual unsigned char get_order() = 0;
  };

  GF* get_field(int order);
}