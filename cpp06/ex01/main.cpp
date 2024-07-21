/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:54:12 by tponnusa          #+#    #+#             */
/*   Updated: 2024/05/21 15:53:44 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
    Data originalData;

    originalData.id = 42;
    originalData.name = "Tamil";
    
    Data* originalPtr = &originalData;

    // Serialize the pointer
    uintptr_t serialized = Serializer::serialize(originalPtr);
    
    // Deserialize the pointer back
    Data* deserializedPtr = Serializer::deserialize(serialized);

    // Verify that the deserialized pointer matches the original pointer
    if (deserializedPtr == originalPtr) {
        std::cout << "The deserialized pointer matches the original pointer." << std::endl;
    } else {
        std::cout << "The deserialized pointer does not match the original pointer." << std::endl;
    }

    // Additionally, we can check the data content to be sure
    if (deserializedPtr->id == originalData.id && deserializedPtr->name == originalData.name) 
    {
        std::cout << "The data content matches." << std::endl;
    } else {
        std::cout << "The data content does not match." << std::endl;
    }
    return (0);
}
