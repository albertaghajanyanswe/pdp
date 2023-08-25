#ifndef VECTOR_H
#define VECTOR_H

class Vector {
private:
	int *vector;
	int size;
	bool InitVector(const int* const p1, const int s);

public:
	Vector(const int size=5);
	Vector(const Vector& a);
	const Vector& Show()const;
	~Vector();
	int getSize()const;
	bool insert(const int& index, const int& value);
	bool remove(const int index);
	int retrieve(int index);
};
#endif
