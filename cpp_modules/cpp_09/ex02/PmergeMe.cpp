/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwookim <chanwookim@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 20:32:09 by dkham             #+#    #+#             */
/*   Updated: 2024/06/03 01:46:39 by chanwookim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


PmergeMe::PmergeMe(): input()
	, jacobsthalIndexVector()
	, oddElement(0)
	, elemPairsVector()
	, mainVector()
	, pendingVector()
	, elemPairsList()
	, mainList()
	, pendingList()
{}


PmergeMe::PmergeMe(const PmergeMe& other)
	: input(other.input)
	, jacobsthalIndexVector(other.jacobsthalIndexVector)
	, oddElement(other.oddElement)
	, elemPairsVector(other.elemPairsVector)
	, mainVector(other.mainVector)
	, pendingVector(other.pendingVector)
	, elemPairsList(other.elemPairsList)
	, mainList(other.mainList)
	, pendingList(other.pendingList)
{}


PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	
	if (this != &other)
	{
		input = other.input;
		jacobsthalIndexVector = other.jacobsthalIndexVector;
		oddElement = other.oddElement;
		elemPairsVector = other.elemPairsVector;
		mainVector = other.mainVector;
		pendingVector = other.pendingVector;
		elemPairsList = other.elemPairsList;
		mainList = other.mainList;
		pendingList = other.pendingList;
	}
	return (*this);
}


PmergeMe::~PmergeMe()
{}


void PmergeMe::checkValidInput(int argc, char** argv) {

	if (argc < 2) {
		throw (std::invalid_argument("Error: No input arguments provided."));
	}


	for (int i = 1; i < argc; i++) {
		if (isPositiveInteger(argv[i]) == true) {
			input.push_back(std::atoi(argv[i]));
		}
	}
    

    std::set<int> set;
    for (size_t i = 0; i < input.size(); i++) {
        if (set.find(input[i]) == set.end()) {
            set.insert(input[i]);
        }
        else {
            throw std::invalid_argument("Error: Duplicate elements found in the input sequence.");
        }
    }
}

bool PmergeMe::isPositiveInteger(const std::string& inputString) {
	std::istringstream iss(inputString);

	int value;
	iss >> value;


	if (iss.eof() == false) {
		throw std::invalid_argument("Error: \"" + inputString + "\" contains non-integer values.");
	}

	if (value < 0) {
		throw std::invalid_argument("Error: \"" + inputString + "\" is not a positive integer.");
	}
	return (true);
}


void PmergeMe::runSort() {
	double vectorTime = runSortForVector();
	double listTime = runSortForList();
    

    std::cout << "Before: ";
    for (size_t i = 0; i < input.size(); i++) {
        std::cout << input[i] << " ";
    }
    std::cout << std::endl;
    

    std::cout << "After:  ";
    for (size_t i = 0; i < mainVector.size(); i++) {
        std::cout << mainVector[i] << " ";
    }
    std::cout << std::endl;
    

	printTime("vector", vectorTime);
	printTime("list", listTime);
}

double PmergeMe::runSortForVector() {
	clock_t start = clock();
	fordJohnsonVector();
	clock_t end = clock();
	
	double elapsedTime = (double)(end - start) / CLOCKS_PER_SEC * 1000000;
	return (elapsedTime);
}

double PmergeMe::runSortForList() {
	clock_t start = clock();
	fordJohnsonList();
	clock_t end = clock();
	
	double elapsedTime = (double)(end - start) / CLOCKS_PER_SEC * 1000000;

	return (elapsedTime);
}


void PmergeMe::fordJohnsonVector() {
    std::cout << "|     VECTOR     |" << std::endl;
	std::cout << "*** createPairsInDescending ***" << std::endl;
	createPairsInDescending();
	printVectorPairs();

	std::cout << "*** mergeSortVector ***" << std::endl;
	mergeSortVector(0, elemPairsVector.size() - 1);
	printVectorPairs();

	std::cout << "*** splitPairsToMainPendingVector ***" << std::endl;
    splitPairsToMainPendingVector();
	printAfterSplitingMainPendingVector();
	
	std::cout << "*** insertionSortVector ***" << std::endl;
	insertionSortVector();

	std::cout << "RESULT: " << std::endl;
	printMainVector();
}


void PmergeMe::createPairsInDescending() {
    elemPairsVector.clear();
    elemPairsList.clear();


    for (size_t i = 0; i < input.size() - 1; i += 2) {
        std::pair<int, int> pair;
        

        if (input[i] < input[i + 1]) {
            pair = std::make_pair(input[i + 1], input[i]);
        }
        else {
            pair = std::make_pair(input[i], input[i + 1]);
        }

        elemPairsVector.push_back(pair);
        elemPairsList.push_back(pair);
    }
    

    if (input.size() % 2 != 0) {
        oddElement = input[input.size() - 1];
    }
}


void PmergeMe::printVectorPairs() {
	for (size_t i = 0; i < elemPairsVector.size(); i++) {
		std::cout << "(" << elemPairsVector[i].first;
		std::cout << ", " << elemPairsVector[i].second << ")";
		std::cout << std::endl;
	}

	if (input.size() % 2 != 0) {
		std::cout << "(" << oddElement <<  ")" <<std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;
}


void PmergeMe::mergeSortVector(int left, int right) {
    
    if (left >= right)
        return;

	int mid = left + (right - left) / 2;
	
    mergeSortVector(left, mid);

    mergeSortVector(mid + 1, right);

    mergeSortedHalvesVector(left, mid, right);
}

void PmergeMe::mergeSortedHalvesVector(int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int Rightsize = right - mid;

    std::vector<std::pair<int, int> > leftPair(leftSize);
    std::vector<std::pair<int, int> > rightPair(Rightsize);

    for (int i = 0; i < leftSize; i++) {
        leftPair[i] = elemPairsVector[left + i];
    }
    for (int i = 0; i < Rightsize; i++) {
        rightPair[i] = elemPairsVector[mid + 1 + i];
    }

    int indexLeft = 0, indexRight = 0, mergeIndex = left;

    while (indexLeft < leftSize && indexRight < Rightsize) {
        if (leftPair[indexLeft].first <= rightPair[indexRight].first) {
            elemPairsVector[mergeIndex] = leftPair[indexLeft++];
        } else { 
            elemPairsVector[mergeIndex] = rightPair[indexRight++];
        }
        mergeIndex++;
    }


    while (indexLeft < leftSize) {
        elemPairsVector[mergeIndex++] = leftPair[indexLeft++];
    }


    while (indexRight < Rightsize) {
        elemPairsVector[mergeIndex++] = rightPair[indexRight++];
    }
}

void PmergeMe::splitPairsToMainPendingVector() {
	mainVector.clear();
	pendingVector.clear();

    for (size_t i = 0; i < elemPairsVector.size(); i++) {
        mainVector.push_back(elemPairsVector[i].first);
        pendingVector.push_back(elemPairsVector[i].second);
    }
}


void PmergeMe::insertionSortVector() {

	createJacobsthalIndexes(pendingVector.size());
	printJacobsthalIndex();
	

	insertElemWithJacobsthalIndexesVector();
    insertOddElemVector();
}

void PmergeMe::createJacobsthalIndexes(int pendingElementSize) {

    jacobsthalIndexVector.clear();


    if (pendingElementSize < 1)
        return;


    std::vector<int> jacobsthalNumbers;
    int i = 1;
    while (true) {
        i++;
        int number = jacobsthal(i);
        jacobsthalNumbers.push_back(number);
        if (number > pendingElementSize)
            break;
    }


    std::set<int> usedNum;

    jacobsthalIndexVector.push_back(1);
    usedNum.insert(1);


    int number = jacobsthalNumbers.front();

    while (true) {
        if (usedNum.find(number) == usedNum.end()) {
            jacobsthalIndexVector.push_back(number);
            usedNum.insert(number);
            number--;
        } else {
            if (jacobsthalNumbers.empty())
                break;
            number = jacobsthalNumbers.front();
            if (number > pendingElementSize) {
                number = pendingElementSize;
            }
            jacobsthalNumbers.erase(jacobsthalNumbers.begin());
        }
    }
}

int PmergeMe::jacobsthal(int n) {
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;
    

    int twoTermsAgo = 0;
    int previousTerm = 1;
    int currentTerm = 0;


    for (int index = 2; index <= n; index++) {
        currentTerm = previousTerm + 2 * twoTermsAgo;
        

        twoTermsAgo = previousTerm;
        previousTerm = currentTerm;
    }


    return currentTerm;
}

void PmergeMe::insertElemWithJacobsthalIndexesVector() {
	for (size_t index = 0; index < jacobsthalIndexVector.size(); ++index)
		{
			int jacobsthalIndex = jacobsthalIndexVector[index];
			int value = pendingVector[jacobsthalIndex - 1];
			int position = binarySearchVector(value);

			printInsertionDetails(jacobsthalIndex, value, position);
			std::cout << "Before: " << std::endl;
			printMainVector();

			mainVector.insert(mainVector.begin() + position, value);

			std::cout << "After: " << std::endl;
			printMainVector();
		}
		pendingVector.clear();
}


int PmergeMe::binarySearchVector(int value) {
	int left = 0;
	int right = mainVector.size() - 1;
    int correspondingAk;
    

    for (size_t i = 0; i < elemPairsVector.size(); i++) {
        if (elemPairsVector[i].second == value) {
            correspondingAk = elemPairsVector[i].first;
            break;
        }
    }
    

    for (size_t i = 0; i < mainVector.size(); i++) {
        if (mainVector[i] == correspondingAk) {
            right = i;
            break;
        }
    }
    

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (mainVector[mid] < value) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
		return (left);
}


void PmergeMe::insertOddElemVector() {
    std::cout << "insert odd element" << std::endl;
    if (input.size() % 2 != 0)
	{
        int position = binarySearchVector(oddElement);
        mainVector.insert(mainVector.begin() + position, oddElement);
    }
}


void PmergeMe::fordJohnsonList() {
    std::cout << "|     LIST     |" << std::endl;
	std::cout << "*** createPairsInDescending ***" << std::endl;
	createPairsInDescending();
	printListPairs();

	std::cout << "*** mergeSortList ***" << std::endl;
	mergeSortList(elemPairsList.begin(), elemPairsList.end());
	printListPairs();

	std::cout << "*** splitPairsToMainPendingList ***" << std::endl;
    splitPairsToMainPendingList();
	printAfterSplitingMainPendingList();

    std::cout << "*** insertionSortList ***" << std::endl;
	insertionSortList();

	std::cout << "RESULT: " << std::endl;
	printMainList();
}


void PmergeMe::splitPairsToMainPendingList() {
	mainList.clear();
	pendingList.clear();
	for (std::list<std::pair<int, int> >::iterator it = elemPairsList.begin(); it != elemPairsList.end(); ++it) {
		mainList.push_back(it->first);
		pendingList.push_back(it->second);
	}
}


void PmergeMe::mergeSortList(std::list<std::pair<int, int> >::iterator left, std::list<std::pair<int, int> >::iterator right) {

    std::list<std::pair<int, int> >::iterator nextLeft = left;
    nextLeft++;
    

    if (left == right || nextLeft == right) {
        return;
    }
    

	std::list<std::pair<int, int> >::iterator mid = left;
	std::advance(mid, std::distance(left, right) / 2);

	mergeSortList(left, mid);
	mergeSortList(mid, right);
	mergeSortedHalvesList(left, mid, right);
}

void PmergeMe::mergeSortedHalvesList(std::list<std::pair<int, int> >::iterator left, std::list<std::pair<int, int> >::iterator mid, std::list<std::pair<int, int> >::iterator right) {

    std::list<std::pair<int, int> > tempList;
    

    std::list<std::pair<int, int> >::iterator leftPair = left;
    std::list<std::pair<int, int> >::iterator rightPair = mid;
    

    while (leftPair != mid && rightPair != right) {

        if (leftPair->first <= rightPair->first) {
            tempList.push_back(*leftPair);
            leftPair++;
        }
        else {
            tempList.push_back(*rightPair);
            rightPair++;
        }
    }


    while (leftPair != mid) {
        tempList.push_back(*leftPair);
        leftPair++;
    }


    while (rightPair != right) {
        tempList.push_back(*rightPair);
        rightPair++;
    }


    std::copy(tempList.begin(), tempList.end(), left);
}


void PmergeMe::insertionSortList() {
	createJacobsthalIndexes(pendingList.size());
	printJacobsthalIndex();

	insertElementsWithJacobsthalIndexesList();
    insertOddElementList();
}

void PmergeMe::insertElementsWithJacobsthalIndexesList() {
    for (size_t index = 0; index < jacobsthalIndexVector.size(); ++index) 
    {
        int jacobsthalIndex = jacobsthalIndexVector[index];

        std::list<int>::iterator valueIt = pendingList.begin();
        std::advance(valueIt, jacobsthalIndex - 1);
        int value = *valueIt;

        int position = binarySearchList(value);

        printInsertionDetails(jacobsthalIndex, value, position);
		
		std::cout << "Before: " << std::endl;
		printMainList();

        std::list<int>::iterator it = mainList.begin();
        std::advance(it, position);
        mainList.insert(it, value);

		std::cout << "After: " << std::endl;
		printMainList();
    }

    pendingList.clear();
}


void PmergeMe::insertOddElementList() {
    std::cout << "insert odd element" << std::endl;
    if (input.size() % 2 != 0)
	{
        int position = binarySearchList(oddElement);

        std::list<int>::iterator it = mainList.begin();
        std::advance(it, position);
        mainList.insert(it, oddElement);

    }
}

int PmergeMe::binarySearchList(int value) {

    if (mainList.empty()) {
        return 0;
    }

    int correspondingAk;

    for (std::list<std::pair<int, int> >::const_iterator it = elemPairsList.begin(); it != elemPairsList.end(); ++it) {
        if (it->second == value) {
            correspondingAk = it->first;
            break;
        }
    }


    std::list<int>::iterator left = mainList.begin();
    std::list<int>::iterator right = mainList.end();


    std::list<int>::iterator correspondingIt;
    for (correspondingIt = mainList.begin(); correspondingIt != mainList.end(); ++correspondingIt) {
        if (*correspondingIt == correspondingAk) {
            break;
        }
    }


    if (correspondingIt != mainList.end()) {
        right = correspondingIt;
    }

    
    std::list<int>::iterator mid;

    int remainingElements = std::distance(left, right);

    
    while (remainingElements > 0 && left != right) {
        int moveDistance = remainingElements / 2;
        mid = left;
        std::advance(mid, moveDistance);

        if (*mid < value) {
            std::advance(left, moveDistance + 1);
            remainingElements -= (moveDistance + 1);
        }
        else {
            right = mid;
            remainingElements = moveDistance;
        }
    }

    return std::distance(mainList.begin(), left);
}


void PmergeMe::printTime(std::string containerType, double time) {
	std::cout << "Time to process a range of ";
	std::cout << input.size();
	std::cout << " elements with std::" << containerType << " ";
	std::cout << time;
	std::cout << " us" << std::endl;
}


void PmergeMe::printListPairs() {
	std::list<std::pair<int, int> >::iterator it;
	for (it = elemPairsList.begin(); it != elemPairsList.end(); it++) {
        std::cout << "(" << it->first;
        std::cout << ", " << it->second << ")";
        std::cout << std::endl;
	}

    if (input.size() % 2 != 0) {
        std::cout << "(" << oddElement <<  ")" <<std::endl;
        std::cout << std::endl;
	}
	std::cout << std::endl;
}

void PmergeMe::printAfterSplitingMainPendingVector() {
	printMainVector();
	printPendingVector();
	printOddElement();
}

void PmergeMe::printAfterSplitingMainPendingList() {
	printMainList();
	PrintPendingElementsList();
	printOddElement();
}

void PmergeMe::printMainVector() {
    std::cout << "Main Vector: [";
    for (std::vector<int>::iterator it = mainVector.begin(); it != mainVector.end(); ++it)
    {
        if (it != mainVector.begin())
        {
            std::cout << ", ";
        }
        std::cout << *it;
    }
    std::cout << "]" << std::endl;
	std::cout << std::endl;

}

void PmergeMe::printPendingVector() {
    std::cout << "Pending Vector: [";
    for (std::vector<int>::iterator it = pendingVector.begin(); it != pendingVector.end(); ++it)
    {
        if (it != pendingVector.begin())
        {
            std::cout << ", ";
        }
        std::cout << *it;
    }
    std::cout << "]" << std::endl;
	std::cout << std::endl;
}

void PmergeMe::printOddElement() {
	if (input.size() % 2 != 0)
	{
		std::cout << "OddElement: ";
		std::cout << oddElement << std::endl;
		std::cout << std::endl;
	}
}

void PmergeMe::printJacobsthalIndex() {
    std::cout << "Jacobsthal Index: [";
    for (size_t index = 0; index < jacobsthalIndexVector.size(); ++index)
    {
        if (index != 0)
        {
            std::cout << ", ";
        }
        std::cout << jacobsthalIndexVector[index];
    }
    std::cout << "]" << std::endl;
	std::cout << std::endl;
}

void PmergeMe::printInsertionDetails(int jacobsthalIndex, int value, int position) {
    std::cout << "Jacobsthal Index: " << jacobsthalIndex << std::endl; 
    std::cout << "Insert value: " << value << std::endl; 
	std::cout << "Position to insert in Main: " << position << std::endl;
}

void PmergeMe::printMainList() {
    std::cout << "Main List: NULL <-> ";
    for (std::list<int>::iterator it = mainList.begin(); it != mainList.end(); ++it)
    {
        std::cout << "[" << *it << "] <-> ";
    }
    std::cout << "NULL" << std::endl;
    std::cout << std::endl;
}

void PmergeMe::PrintPendingElementsList() {
    std::cout << "Pending List: NULL <-> ";
    for (std::list<int>::iterator it = pendingList.begin(); it != pendingList.end(); ++it)
    {
        std::cout << "[" << *it << "] <-> ";
    }
    std::cout << "NULL" << std::endl;
    std::cout << std::endl;
}
