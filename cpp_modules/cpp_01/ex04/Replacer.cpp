/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:19:27 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/28 14:46:21 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

Replacer::Replacer(std::string filename, std::string s1, std::string s2)
{
  this->_filename = filename;
  this->_s1 = s1;
  this->_s2 = s2;
}

Replacer::~Replacer(void)
{
}


void Replacer::replace(void)
{
  std::ifstream ifs(_filename);
  std::string line;
  std::string new_line;

  if (!ifs.is_open())
  {
    std::cout << "Error: cannot open input file" << std::endl;
    exit(1);
  }

  // .replace 파일 생성
  std::ofstream ofs(_filename + ".replace");

  if (ofs.is_open())
  {
    while (std::getline(ifs, line))
    {

      size_t pos = 0;
		  while (true)
		  {
		  	pos = line.find(_s1, pos);
		  	if (pos == std::string::npos)
		  	{
		  		break ;
		  	}
		  	line.erase(pos, _s1.length());
		  	line.insert(pos, _s2);
		  	pos += _s2.length();
		  }
      ofs << line;
		  if (ifs.eof())
			  break ;
		  ofs << std::endl;
    }
    ifs.close();
    ofs.close();
  }
  else
  {
    std::cout << "Error: cannot open output file" << std::endl;
    exit(1);
  }
}

