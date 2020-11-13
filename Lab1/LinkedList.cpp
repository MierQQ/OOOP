#include "LinkedList.h"

LinkedList::Node::Node()
{
	next = nullptr;
	prev = nullptr;
	value = value_type();
}

LinkedList::Node::Node(value_type inputValue)
{
	next = nullptr;
	prev = nullptr;
	value = inputValue;
}

LinkedList::Node::Node(Node* inputPrev, Node* inputNext, value_type inputValue)
{
	next = inputNext;
	prev = inputPrev;
	value = inputValue;
}

LinkedList::iterator::iterator()
{
	currentNode = nullptr;
}

LinkedList::iterator& LinkedList::iterator::operator=(const iterator& other)
{
	currentNode = other.currentNode;
	return *this;
}

bool LinkedList::iterator::operator!=(const iterator& other) const
{
	return currentNode != other.currentNode;
}

bool LinkedList::iterator::operator==(const iterator& other) const
{
	return currentNode == other.currentNode;
}

value_type& LinkedList::iterator::operator*()
{
	return currentNode->value;
}

value_type* LinkedList::iterator::operator->()
{
	return &(currentNode->value);
}

LinkedList::iterator& LinkedList::iterator::operator++()
{
	currentNode = currentNode->next;
	return *this;
}

LinkedList::iterator LinkedList::iterator::operator++(int)
{
	iterator lastIterator = *this;
	++(*this);
	return lastIterator;
}

LinkedList::iterator& LinkedList::iterator::operator--()
{
	currentNode = currentNode->prev;
	return *this;
}

LinkedList::iterator LinkedList::iterator::operator--(int)
{
	iterator nextIterator = *this;
	--(*this);
	return nextIterator;
}

LinkedList::const_iterator::const_iterator()
{
	currentNode = nullptr;
}

LinkedList::const_iterator& LinkedList::const_iterator::operator=(const const_iterator& other)
{
	currentNode = other.currentNode;
	return *this;
}

bool LinkedList::const_iterator::operator!=(const const_iterator& other) const
{
	return currentNode != other.currentNode;
}

bool LinkedList::const_iterator::operator==(const const_iterator& other) const
{
	return currentNode == other.currentNode;
}

const value_type& LinkedList::const_iterator::operator*() const
{
	return currentNode->value;
}

const value_type* LinkedList::const_iterator::operator->() const
{
	return &(currentNode->value);
}

LinkedList::const_iterator& LinkedList::const_iterator::operator++()
{
	currentNode = currentNode->next;
	return *this;
}

LinkedList::const_iterator LinkedList::const_iterator::operator++(int)
{
	const_iterator lastNode = *this;
	++(*this);
	return lastNode;
}

LinkedList::const_iterator& LinkedList::const_iterator::operator--()
{
	currentNode = currentNode->prev;
	return *this;
}

LinkedList::const_iterator LinkedList::const_iterator::operator--(int)
{
	const_iterator nextNode = *this;
	--(*this);
	return nextNode;
}

LinkedList::LinkedList()
{
	len = 0;
	head.next = &head;
	head.prev = &head;
}

LinkedList::LinkedList(const LinkedList& other) : LinkedList()
{
	for (const_iterator iteratorForSourceList = other.cbegin(); iteratorForSourceList != other.cend(); ++iteratorForSourceList) {
		push_back(*iteratorForSourceList);
	}
}

LinkedList::LinkedList(LinkedList&& other) noexcept
{
	head = other.head;
	head.next->prev = &head;
	head.prev->next = &head;
	len = other.len;
	other.head.next = &other.head;
	other.head.prev = &other.head;
	other.len = 0;
}

LinkedList& LinkedList::operator=(const LinkedList& other)
{
	if (other != *this) {
		clear();
		for (auto element : other) {
			push_back(element);
		}
	}
	return *this;
}

LinkedList& LinkedList::operator=(LinkedList&& other) noexcept
{
	if (other != *this) {
		clear();
		head = other.head;
		head.next->prev = &head;
		head.prev->next = &head;
		len = other.len;
		other.head.next = &other.head;
		other.head.prev = &other.head;
		other.len = 0;
	}
	return *this;
}



LinkedList::~LinkedList()
{
	clear();
}

LinkedList::iterator LinkedList::begin(){
	iterator result;
	result.currentNode = head.next;
	return result;
}

LinkedList::const_iterator LinkedList::begin() const
{
	const_iterator result;
	result.currentNode = head.next;
	return result;
}

LinkedList::const_iterator LinkedList::cbegin() const
{
	const_iterator result;
	result.currentNode = head.next;
	return result;
}

LinkedList::iterator LinkedList::end()
{
	iterator result;
	result.currentNode = head.next->prev;
	return result;
}

LinkedList::const_iterator LinkedList::end() const
{
	const_iterator result;
	result.currentNode = head.next->prev;
	return result;
}

LinkedList::const_iterator LinkedList::cend() const
{
	const_iterator result;
	result.currentNode = head.next->prev;
	return result;
}

int LinkedList::size() const
{
	return len;
}

bool LinkedList::empty() const
{
	return len == 0;
}

value_type& LinkedList::front()
{
	if (head.next != &head) {
		return head.next->value;
	}
	else {
		throw("trying to access to empty list");
	}
}

const value_type& LinkedList::front() const
{
	if (head.next != &head) {
		return head.next->value;
	}
	else {
		throw("trying to access to empty list");
	}
}

value_type& LinkedList::back()
{
	if (head.prev != &head) {
		return head.prev->value;
	}
	else {
		throw("trying to access to empty list");
	}
}

const value_type& LinkedList::back() const
{
	if (head.prev != &head) {
		return head.prev->value;
	}
	else {
		throw("trying to access to empty list");
	}
}

LinkedList::iterator LinkedList::erase(iterator position)
{
	if (position != end()) {
		--len;
		Node* toDeleteNode = position.currentNode;
		iterator front;
		iterator back;
		++position;
		back = position;
		----position;
		front = position;
		back.currentNode->prev = front.currentNode;
		front.currentNode->next = back.currentNode;
		delete toDeleteNode;
		return back;
	}
	else {
		throw("erase end Node");
	}
}

LinkedList::iterator LinkedList::erase(iterator begin, iterator end)
{
	auto iterator = begin;
	while (iterator != end) {
		auto toDelete = iterator++;
		erase(toDelete);
	}
	return end;
}

int LinkedList::remove(const value_type& value)
{
	int count = 0;
	for (iterator toDelete = begin(); toDelete != end(); ++toDelete) {
		if (*toDelete == value) {
			++count;
			erase(toDelete);
		}
	}
	return count;
}

void LinkedList::clear()
{
	while (!empty()) {
		pop_front();
	}
}

void LinkedList::pop_back()
{
	if (!empty()) {
		erase(--end());
	}
}

void LinkedList::pop_front()
{
	if (!empty()) {
		erase(begin());
	}
}

void LinkedList::push_back(const value_type& value)
{
	insert(end(), value);
}

void LinkedList::push_front(const value_type& value)
{
	insert(begin(), value);
}

LinkedList::iterator LinkedList::insert(iterator before, const value_type& value)
{
	iterator after = --before;
	++before;
	Node* newNode = new Node(after.currentNode, before.currentNode, value);
	after.currentNode->next = newNode;
	before.currentNode->prev = newNode;
	++len;
	return before;
}

LinkedList& LinkedList::operator+=(const LinkedList& other)
{
	for (const_iterator toAdd = other.cbegin(); toAdd != other.cend(); ++toAdd) {
		push_back(*toAdd);
	}
	return *this;
}

bool operator!=(const LinkedList& left, const LinkedList& right)
{
	LinkedList::const_iterator first = left.cbegin();
	LinkedList::const_iterator second = right.cbegin();
	if(&left == &right) {
		return false;
	}
	while (true) {
		if (first == left.cend() && second != right.cend() ||
			first != left.cend() && second == right.cend()) {
			return false;
		}
		if (first != left.cend() && second == right.cend()) {
			return true;
		}
		if (*first == *second) {
			++first;
			++second;
		}
		else {
			return false;
		}
	}
}



bool operator==(const LinkedList& left, const LinkedList& right)
{
	return !(left != right);
}
