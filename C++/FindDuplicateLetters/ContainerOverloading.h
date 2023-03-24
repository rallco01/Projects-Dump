template< typename T , template<typename ELEM, typename ALLOC=std::allocator<ELEM>> class Container>
std::ostream& operator<< (std::ostream& out, const Container<T>& container)
{
	typename Container<T>::const_iterator beg = container.begin();
	
	out << "[";
	const char* separator = "";
	for ( const auto& element : container )
	{
		out << separator;
		out << element;
		separator = ", ";
	}
	out << "]";
	
	return out;
}

template<typename T1, size_t arrSize, typename = std::enable_if_t<!std::is_same<T1,char>::value>>
std::ostream& operator <<( std::ostream& out, const T1( & arr )[arrSize] )
{
	out << "[";
	if ( arrSize )
	{
		const char* separator = "";
		for ( const auto& element : arr )
		{
			out << separator;
			out << element;
			separator = ", ";
		}
	}
	out << "]";
	return out;
}