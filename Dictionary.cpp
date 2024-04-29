/*
 * Dictionary.cpp
 * 
 * Description: Dictonary data collection ADT class.
 *              BST-based implementation.
 *              Duplicated elements not allowed.
 *              
 * Author: AL
 * Date: Feb. 2022
 */

 #pragma once

#include "BST.h"
#include "Dictionary.h"

    // Constructors and destructor:
template <class ElementType>
Dictionary<ElementType>::Dictionary()
{

keyValuePairs = new BST<ElementType>;

}
// Default constructor
template <class ElementType>
Dictionary<ElementType>::Dictionary(ElementType& element) 
{
  this->keyValuePairs = new BST <ElementType> (element);
  keyValuePairs->elmentCount++;
}
// Parameterized constructor 
template <class ElementType>
Dictionary<ElementType>::~Dictionary()
{
  keyValuePairs->root = nullptr;
  keyValuePairs->elementCount = 0;
}// Destructor 
	
    // Dictionary operations:
template <class ElementType>
unsigned int Dictionary<ElementType>::getElementCount() const
{
  return keyValuePairs->elementCount;
}
	
	// Description: Puts "newElement" into the dictionary.
	// ...
template <class ElementType>
	void Dictionary<ElementType>::put(const ElementType& newElement)
{
  keyValuePairs->insert(newElement);
  return;
}

	// Description: Gets "newElement" from the dictionary.
	// ...
template <class ElementType>
	ElementType& Dictionary<ElementType>::get(const ElementType& targetElement) const
{
  return keyValuePairs->retrieve(targetElement);
}

template <class ElementType>
    void Dictionary<ElementType>::displayContent(void visit(const ElementType&  )) const
{
    keyValuePairs->traverseInOrder(visit);
}
	 // end Dictionary