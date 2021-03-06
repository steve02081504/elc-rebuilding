//iterator.hpp
//at namespace elc::defs::base
/*
未完成的elc解释器base文件
由steve02081504与Alex0125设计、编写
转载时请在不对此文件做任何修改的同时注明出处
项目地址：https://github.com/steve02081504/ELC
*/
namespace iterator_n{
	template<typename base_t>
	struct reverse_base_t:base_t{
		typedef reverse_base_t<base_t> this_t;
		//typedef base_t base_t;
	protected:
		[[nodiscard]]auto get_before()noexcept_as(declvalue(base_t).get_next()){return base_t::get_next();}
		[[nodiscard]]auto get_next()noexcept_as(declvalue(base_t).get_before()){return base_t::get_before();}
		using base_t::get_handle;
	};

	template<typename value_t,typename base_t_w>
	class same_base_t{
		template<typename,typename>
		friend class same_base_t;
	protected:
		typedef same_base_t<value_t,base_t_w>this_t;
		//
		base_t_w _m;
		//
		[[nodiscard]]constexpr bool is_handle_getter_noexcept()noexcept{
			if constexpr(type_info<decltype(*declvalue(base_t_w))> == type_info<value_t>)
				return true;
			elseif constexpr(is_pointer<base_t_w>)
				return noexcept(declvalue(base_t_w)->get_handle());
			else
				return noexcept(declvalue(base_t_w).get_handle());
		}
		[[nodiscard]]inline value_t*handle_getter()noexcept(is_handle_getter_noexcept()){
			if constexpr(type_info<decltype(*declvalue(base_t_w))> == type_info<value_t>)
				return _m;
			elseif constexpr(is_pointer<base_t_w>)
				return _m->get_handle();
			else
				return _m.get_handle();
		}
		//
		[[nodiscard]]constexpr bool is_next_getter_noexcept()noexcept{
			if constexpr(type_info<decltype(*declvalue(base_t_w))> == type_info<value_t>)
				return true;
			elseif constexpr(is_pointer<base_t_w>)
				return noexcept(declvalue(base_t_w)->get_next());
			else
				return noexcept(declvalue(base_t_w).get_next());
		}
		[[nodiscard]]inline base_t_w next_getter()noexcept(is_next_getter_noexcept()){
			if constexpr(type_info<decltype(*declvalue(base_t_w))> == type_info<value_t>)
				return _m+1;
			elseif constexpr(is_pointer<base_t_w>)
				return _m->get_next();
			else
				return _m.get_next();
		}
		//
		[[nodiscard]]constexpr bool is_before_getter_noexcept()noexcept{
			if constexpr(type_info<decltype(*declvalue(base_t_w))> == type_info<value_t>)
				return true;
			elseif constexpr(is_pointer<base_t_w>)
				return noexcept(declvalue(base_t_w)->get_before());
			else
				return noexcept(declvalue(base_t_w).get_before());
		}
		[[nodiscard]]inline base_t_w before_getter()noexcept(is_before_getter_noexcept()){
			if constexpr(type_info<decltype(*declvalue(base_t_w))> == type_info<value_t>)
				return _m-1;
			elseif constexpr(is_pointer<base_t_w>)
				return _m->get_before();
			else
				return _m.get_before();
		}
	public:
		constexpr void swap_with(this_t&a)noexcept_as(swap(declvalue(base_t_w),declvalue(base_t_w))){swap(_m,a._m);}
		//
		constexpr same_base_t()noexcept=default;
		constexpr same_base_t(base_t_w a)noexcept(construct<base_t_w>.nothrow<base_t_w>):_m(a){}
		constexpr same_base_t(const this_t&a)noexcept(construct<base_t_w>.nothrow<const base_t_w>):_m(a._m){}
		constexpr same_base_t(this_t&&a)noexcept_as(declvalue(this_t).swap_with(a)){swap_with(a);}
		template<typename other_T,typename other_base_t> requires(construct<base_t_w>.able<other_base_t>)
		constexpr same_base_t(const same_base_t<other_T,other_base_t>&a)noexcept(construct<base_t_w>.nothrow<other_base_t>):_m(a._m){}
		~same_base_t()noexcept(destruct.nothrow<base_t_w>)=default;
		[[nodiscard]]constexpr bool operator==(this_t a)const noexcept_as(declvalue(base_t_w)==declvalue(base_t_w)){return _m==a._m;}
		[[nodiscard]]constexpr value_t*operator->()noexcept(is_handle_getter_noexcept()){return handle_getter();}
		[[nodiscard]]constexpr value_t&operator*()noexcept_as(declvalue(this_t).operator->()){return*operator->();}
		[[nodiscard]]constexpr operator value_t*()noexcept_as(declvalue(this_t).operator->()){return operator->();}
		[[nodiscard]]constexpr bool operator==(value_t*a)const noexcept(is_handle_getter_noexcept()&&noexcept(pointer_equal(declvalue(value_t*),declvalue(value_t*)))){return pointer_equal(handle_getter(),a);}
	};
	template<typename value_t,typename base_t_w>
	inline void swap(same_base_t<value_t,base_t_w>&a,same_base_t<value_t,base_t_w>&b)noexcept_as(a.swap_with(b))
	{a.swap_with(b);}

	template<typename value_t,typename base_t_w>
	struct base_iterator_t:same_base_t<value_t,base_t_w>{
		typedef base_iterator_t<value_t,base_t_w> this_t;
		typedef same_base_t<value_t,base_t_w> base_t;
	protected:
		using base_t::is_before_getter_noexcept;
		using base_t::is_next_getter_noexcept;
		using base_t::before_getter;
		using base_t::next_getter;
	public:
		using base_t::base_t;
		constexpr this_t&operator++()&noexcept(is_next_getter_noexcept()){return*this=next_getter();}
		constexpr this_t&operator--()&noexcept(is_before_getter_noexcept()){return*this=before_getter();}
		constexpr this_t operator++(int)&noexcept_as(this_t(++declvalue(this_t))){auto a=*this;operator++();return a;}
		constexpr this_t operator--(int)&noexcept_as(this_t(--declvalue(this_t))){auto a=*this;operator--();return a;}
	};
	template<typename value_t,typename base_t_w>
	base_iterator_t(base_iterator_t<value_t,base_t_w>) -> base_iterator_t<value_t,base_t_w>;
	template<typename value_t,typename base_t_w>
	base_iterator_t(value_t*) -> base_iterator_t<value_t,base_t_w>;

	template<typename value_t,typename base_t_w=value_t*>
	using iterator_t = base_iterator_t<remove_cvref<value_t>,base_t_w>;
	template<typename value_t,typename base_t_w=value_t*>
	using const_iterator_t = base_iterator_t<const remove_cvref<value_t>,base_t_w>;
	template<typename value_t,typename base_t_w=value_t*>
	using reverse_iterator_t = base_iterator_t<remove_cvref<value_t>,reverse_base_t<base_t_w>>;
	template<typename value_t,typename base_t_w=value_t*>
	using reverse_const_iterator_t = base_iterator_t<const remove_cvref<value_t>,reverse_base_t<base_t_w>>;
}
using iterator_n::base_iterator_t;
using iterator_n::iterator_t;
using iterator_n::const_iterator_t;
using iterator_n::reverse_iterator_t;
using iterator_n::reverse_const_iterator_t;

//file_end

