//defs.hpp
//at namespace elc::defs::container
/*
未完成的elc解释器base文件
由steve02081504与Alex0125设计、编写
转载时请在不对此文件做任何修改的同时注明出处
项目地址：https://github.com/steve02081504/ELC
*/
namespace function_n{
	template<class T>
	using function_t=base_function_t<T,true>;

	//[[deprecated("not safe")]]//用这么长名字的人大概知道自己在干啥
	template<class T>
	using may_throw_in_destruct_function_t=base_function_t<T,false>;
}

//file_end

