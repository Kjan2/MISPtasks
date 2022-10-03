#include <vector>
#include <algorithm>
#include <cmath>

template<class T> class PriorityQueue
{
public:
	PriorityQueue() = default;

	PriorityQueue(const std::vector<T>& vector)
	{
		for (auto i : vector)
		{
			push(i);
		}
	};

	PriorityQueue& operator=(const PriorityQueue& other)
	{
		container = other.container;
	}

	PriorityQueue& operator=(PriorityQueue&& other)
	{
		container = other.container;
	}

	void push (const T& value)
	{
		size_t i = container.size();
		container.push_back(value);
		while ((i != 0) && (container[(i - 1) / 2] < container[i]))
		{
            std::swap(container[(i - 1) / 2], container[i]);
			i = (i - 1) / 2;
		}
	}

    void pop()
    {
        std::swap(container[0], container[container.size() - 1]);
        container.pop_back();

        int i = 0;

        size_t right, left, indMax;

        while (true)
        {
            left = i * 2 + 1;
            right = i * 2 + 2;
            indMax = i;

            if (left < container.size() && container[left] > container[indMax]) 
	        {
	            indMax = left;
	        }

            if (right < container.size() && container[right] > container[indMax]) 
	        {
	            indMax = right;
	        }

	        if (indMax == i) 
	        {
	            break;
	        }

	        std::swap(container[i], container[indMax]);

	        i = indMax;
	    }
    }

    T top() const
    {
        return *container.begin();
    }

    size_t size() const
    {
        return container.size();
    } 

    bool empty() const
    {
        return container.empty();
    }
public:
	std::vector<T> container;
};

