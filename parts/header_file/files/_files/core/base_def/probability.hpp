//defs.hpp
//at namespace elc::defs::core
/*
未完成的elc解释器core文件
由steve02081504与Alex0125设计、编写
转载时请在不对此文件做任何修改的同时注明出处
项目地址：https://github.com/steve02081504/ELC
*/
lazy_instantiation struct LIS_name(probability){
	typedef LIS_ID_t(probability)this_t;
	struct base_probability_t{
		virtual ~base_probability_t()noexcept=default;
		virtual setter be_watch()=0;
		virtual void delete_this()const noexcept=0;
		virtual base_probability_t*copy()const noexcept=0;
	};
	struct no_probability_t:type_info_t<no_probability_t>::template
	with_common_attribute<alloc_by_pool>,base_probability_t,build_by_get_only,never_in_array{
		ptr _m;
		no_probability_t(ptr a):_m(a){}
		no_probability_t(const no_probability_t&)noexcept=default;
		virtual ~no_probability_t()noexcept override=default;
		virtual setter be_watch()=0;
		virtual void delete_this()const noexcept override{unget(this);}
		virtual base_probability_t*copy()const noexcept override{return copy_get(this);}
	};
private:
	mutable base_probability_t*_m;
public:
	LIS_name(probability)(ptr a):_m(get<no_probability_t>(a)){}
	constexpr LIS_name(probability)(base_probability_t*a)noexcept:_m(a){}
	LIS_name(probability)(const this_t&a)noexcept:_m(a._m->copy()){}
	LIS_name(probability)(this_t&&a)noexcept:_m(a._m){a._m=null_ptr;}
	~LIS_name(probability)()noexcept{
		if(_m!=null_ptr)
			_m->delete_this();
	}
	operator setter(){
		return _m->be_watch();
	}
	operator const setter()const{
		return _m->be_watch();
	}
	explicit operator bool()const{return bool(_m->be_watch());}
};
lazy_instantiation_name(probability);

//file_end

