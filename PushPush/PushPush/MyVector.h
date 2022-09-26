#pragma once

template <typename T>
class CMyVector
{
	// con and dest
public:
	CMyVector()
		: m_Arr(new T[DEFAULT_CAP])
		, m_size(0)
		, m_capacity(DEFAULT_CAP)

	{
	}
	CMyVector(CMyVector& _other)
		: m_Arr(new T[_other.m_capacity])
		, m_capacity(_other.m_capacity)
		, m_size(_other.m_size)
	{
		for (size_t i = 0; i < m_capacity; i++)
		{
			m_Arr[i] = _other.m_Arr[i];
		}
	}

	~CMyVector()
	{
		delete[] m_Arr;
	}

public:
	// operator
	vector& operator=(vector& _other)
	{
		if (nullptr != this)
		{
			// ������ �迭 ũ�Ⱑ �������� ũ��
			if (m_capacity < _other.m_capacity)
			{
				// ���� �迭 ����
				delete[]m_Arr;
				m_Arr = nullptr;
				//���� �迭 ũ�� �ް�
				m_capacity = _other.m_capacity;
				// �� ũ�Ⱑ���� ���ο� �迭 ����
				m_Arr = new T[m_capacity];
			}

			for (size_t i = 0; i < _other.m_size; ++i)
			{
				m_Arr[i] = _other[i];
				++m_size;
			}

		}

		return *this;
	}

	T& operator[](size_t idx) { return m_Arr[idx]; }


	// function
public:
	void push_back(const T& _Data)
	{
		// �迭�� �ε����� size�� �Ѿ�ٸ�
		if (m_size >= m_capacity)
		{
			if (m_capacity < DEFAULT_CAP)
				m_capacity = DEFAULT_CAP;
			else
			{
				m_capacity *= 2;
				T* newArr = new T[m_capacity];

				for (size_t i = 0; i < m_size; ++i)
					newArr[i] = m_Arr[i];
				delete[] m_Arr;
				m_Arr = newArr;
			}
		}
		m_Arr[m_size++] = _Data;
	}
	T pop_back()
	{
		// ���� �� �ʱ�ȭ �Ƚ��ѵ��� �������� �����Ⱚ�̳� ���Ѱ���
		if (!m_size)
			return m_Arr[--m_size];
	}


public:
	size_t size() { return m_size; }
	size_t capacity() { return m_capacity; }
	bool empty() { return !m_size; }
	void clear() { if (!empty()) m_size = 0; }


private:
	static constexpr size_t DEFAULT_CAP = 32;	// CMyVector���� ��������� ����Ʈ ũ��
												// constexpr : const�� ���� ����� �ϴ¼��� constó���� �Ǵµ�
												// ������ DEFAULT_CAP�� ��� CMyVector���� �Ȱ��� ������ ��� �� ���̱� ������
												// static���� �����Ͽ� ��� CMyVector���� �ϳ��� ������ ����ϰ� ��
												// Ŭ���� ���ο��� �ٰ��� �����Ҽ��ִ� ����������������
	T* m_Arr;
	size_t	m_size;								// size : ��밡���� �迭�� ũ��
	size_t	m_capacity;							// capacity : �޸� �Ҵ� Ȥ�ó� size�� �Ѿ ������ �����Ҽ��� �־ �޸� �Ҵ��� size���� ũ�� �ص�

};
