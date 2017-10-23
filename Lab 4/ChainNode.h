template <class T> class Chain;

template<class T> class ChainNode
{
	public:
		friend class Chain<T>;

	private:
		T data;
		ChainNode<T>* link;
};
