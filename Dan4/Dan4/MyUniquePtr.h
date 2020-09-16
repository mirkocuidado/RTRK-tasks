#ifndef _MY_UNIQUE_PTR_
#define _MY_UNIQUE_PTR_

template<typename T>
class MyUniquePtr {

private:
	T* obj;
public:
	MyUniquePtr() { obj = nullptr; }
	MyUniquePtr(T* o):obj(o) {}
	MyUniquePtr(const MyUniquePtr& o) = delete;
	MyUniquePtr& operator =(MyUniquePtr& o) = delete;
	MyUniquePtr(MyUniquePtr&& o) :obj(o) { o.obj = nullptr; }
	MyUniquePtr& operator =(MyUniquePtr&& o) { obj = o.obj;  o.obj = nullptr; return *this; }
	~MyUniquePtr() { delete obj;  obj = nullptr; std::cout << "Pozdrav, mentolu!"; }

	T& operator *() const { return *obj; }
	T* get() const { return obj; }
	T* operator -> () { return obj; }
};

#endif
