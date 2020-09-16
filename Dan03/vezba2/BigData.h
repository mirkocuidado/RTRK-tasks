#pragma once
#include <iostream>
#include <cstring>

using namespace std;

struct Data {
	Data() = default;

	Data(const unsigned int _x) : data(new unsigned char[_x]), size(_x) {}

	Data(const Data &_d) : data(new unsigned char[_d.size]), size(_d.size) {
		memcpy(data, _d.data, _d.size);
	}

	~Data() {
		delete[] data;
		size = 0;
	};

	Data& operator=(const Data &_d) {
		if (this == &_d) {
			return *this;
		}
		unsigned char *tmp(new unsigned char[_d.size]);
		memcpy(tmp, _d.data, _d.size);
		delete[] data;
		data = tmp;
		size = _d.size;
		return *this;
	}

	//ToDo: Add move ctor

	//ToDo: Add move assignment operator

	bool operator==(const Data &_d) const {
		if (_d.size != size) {
			return false;
		}
		else {
			return !memcmp(data, _d.data, size);
		}
	}

	unsigned char* begin() const {
		return data;
	}

	unsigned char* end() const {
		return data + size;
	}

	unsigned char *data = nullptr;
	unsigned int size = 0;
};

class BigData {
public:
	BigData() = default;

	BigData(const unsigned int _x) : m_data(_x), m_crc(GetCrc(m_data)) {}

	BigData(const BigData &_bd) : m_data(_bd.GetData()), m_crc(_bd.GetCrc()) {}

	~BigData() = default;

	BigData& operator=(const BigData &_bd) {
		if (this == &_bd) {
			return *this;
		}
		m_data = _bd.GetData();
		m_crc = _bd.GetCrc();
		return *this;
	}

	bool operator==(const BigData &_bd) const {
		if (_bd.GetCrc() != m_crc) {
			return false;
		}
		else {
			return _bd.m_data == m_data;
		}
	}

	//ToDo: Add move ctor

	//ToDo: Add move assignment operator


	void dump(ostream &_out) const {
		_out << "CRC: " << m_crc << endl;
		_out << "Data size: " << m_data.size << endl;
		_out << "Data:" << endl;
		for (const auto &e : m_data) {
			_out << e << ' ';
		}
		_out << endl;
	}

	void InvalidateCrc() { m_crc = -1; }

	const Data& GetData() const { return m_data; }

	Data& GetData() { return m_data; }

	unsigned long int GetCrc() const { return m_crc; }

private:
	Data m_data;
	unsigned long int m_crc = -1;

	unsigned long int GetCrc(const Data& d) { return (d.data[0] + d.size) >> 2; }
};
