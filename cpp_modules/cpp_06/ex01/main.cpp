/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:05:58 by chanwoki          #+#    #+#             */
/*   Updated: 2024/01/22 17:24:11 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
  Data originalData;
  originalData.s1 = "Hello World!";
  originalData.n = 42;
  originalData.s2 = "This is the end!";


  uintptr_t serializedData = Serializer::serialize(&originalData);
  Data* deserializedData = Serializer::deserialize(serializedData);


  if (&originalData == deserializedData) {
    std::cout << "Serialization and deserialization successful!" << std::endl;
    std::cout << "originalData.s1: " << originalData.s1 << std::endl;
    std::cout << "originalData.n: " << originalData.n << std::endl;
    std::cout << "originalData.s2: " << originalData.s2 << std::endl;
  } else {
    std::cout << "Something went wrong!" << std::endl;
  }

  return 0;
}
