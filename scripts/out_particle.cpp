// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME out_particle

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "../hep_example/particle.hpp"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *hepcLcLparticlelEfloatgR_Dictionary();
   static void hepcLcLparticlelEfloatgR_TClassManip(TClass*);
   static void *new_hepcLcLparticlelEfloatgR(void *p = 0);
   static void *newArray_hepcLcLparticlelEfloatgR(Long_t size, void *p);
   static void delete_hepcLcLparticlelEfloatgR(void *p);
   static void deleteArray_hepcLcLparticlelEfloatgR(void *p);
   static void destruct_hepcLcLparticlelEfloatgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::hep::particle<float>*)
   {
      ::hep::particle<float> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::hep::particle<float>));
      static ::ROOT::TGenericClassInfo 
         instance("hep::particle<float>", "../hep_example/particle.hpp", 30,
                  typeid(::hep::particle<float>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &hepcLcLparticlelEfloatgR_Dictionary, isa_proxy, 4,
                  sizeof(::hep::particle<float>) );
      instance.SetNew(&new_hepcLcLparticlelEfloatgR);
      instance.SetNewArray(&newArray_hepcLcLparticlelEfloatgR);
      instance.SetDelete(&delete_hepcLcLparticlelEfloatgR);
      instance.SetDeleteArray(&deleteArray_hepcLcLparticlelEfloatgR);
      instance.SetDestructor(&destruct_hepcLcLparticlelEfloatgR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::hep::particle<float>*)
   {
      return GenerateInitInstanceLocal((::hep::particle<float>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::hep::particle<float>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *hepcLcLparticlelEfloatgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::hep::particle<float>*)0x0)->GetClass();
      hepcLcLparticlelEfloatgR_TClassManip(theClass);
   return theClass;
   }

   static void hepcLcLparticlelEfloatgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_hepcLcLparticlelEfloatgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::hep::particle<float> : new ::hep::particle<float>;
   }
   static void *newArray_hepcLcLparticlelEfloatgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::hep::particle<float>[nElements] : new ::hep::particle<float>[nElements];
   }
   // Wrapper around operator delete
   static void delete_hepcLcLparticlelEfloatgR(void *p) {
      delete ((::hep::particle<float>*)p);
   }
   static void deleteArray_hepcLcLparticlelEfloatgR(void *p) {
      delete [] ((::hep::particle<float>*)p);
   }
   static void destruct_hepcLcLparticlelEfloatgR(void *p) {
      typedef ::hep::particle<float> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::hep::particle<float>

namespace ROOT {
   static TClass *vectorlEintgR_Dictionary();
   static void vectorlEintgR_TClassManip(TClass*);
   static void *new_vectorlEintgR(void *p = 0);
   static void *newArray_vectorlEintgR(Long_t size, void *p);
   static void delete_vectorlEintgR(void *p);
   static void deleteArray_vectorlEintgR(void *p);
   static void destruct_vectorlEintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<int>*)
   {
      vector<int> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<int>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<int>", -2, "vector", 447,
                  typeid(vector<int>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEintgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<int>) );
      instance.SetNew(&new_vectorlEintgR);
      instance.SetNewArray(&newArray_vectorlEintgR);
      instance.SetDelete(&delete_vectorlEintgR);
      instance.SetDeleteArray(&deleteArray_vectorlEintgR);
      instance.SetDestructor(&destruct_vectorlEintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<int> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<int>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<int>*)0x0)->GetClass();
      vectorlEintgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEintgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<int> : new vector<int>;
   }
   static void *newArray_vectorlEintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<int>[nElements] : new vector<int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEintgR(void *p) {
      delete ((vector<int>*)p);
   }
   static void deleteArray_vectorlEintgR(void *p) {
      delete [] ((vector<int>*)p);
   }
   static void destruct_vectorlEintgR(void *p) {
      typedef vector<int> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<int>

namespace ROOT {
   static TClass *vectorlEhepcLcLparticlelEfloatgRsPgR_Dictionary();
   static void vectorlEhepcLcLparticlelEfloatgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEhepcLcLparticlelEfloatgRsPgR(void *p = 0);
   static void *newArray_vectorlEhepcLcLparticlelEfloatgRsPgR(Long_t size, void *p);
   static void delete_vectorlEhepcLcLparticlelEfloatgRsPgR(void *p);
   static void deleteArray_vectorlEhepcLcLparticlelEfloatgRsPgR(void *p);
   static void destruct_vectorlEhepcLcLparticlelEfloatgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<hep::particle<float> >*)
   {
      vector<hep::particle<float> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<hep::particle<float> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<hep::particle<float> >", -2, "vector", 447,
                  typeid(vector<hep::particle<float> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEhepcLcLparticlelEfloatgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<hep::particle<float> >) );
      instance.SetNew(&new_vectorlEhepcLcLparticlelEfloatgRsPgR);
      instance.SetNewArray(&newArray_vectorlEhepcLcLparticlelEfloatgRsPgR);
      instance.SetDelete(&delete_vectorlEhepcLcLparticlelEfloatgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEhepcLcLparticlelEfloatgRsPgR);
      instance.SetDestructor(&destruct_vectorlEhepcLcLparticlelEfloatgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<hep::particle<float> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<hep::particle<float> >*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEhepcLcLparticlelEfloatgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<hep::particle<float> >*)0x0)->GetClass();
      vectorlEhepcLcLparticlelEfloatgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEhepcLcLparticlelEfloatgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEhepcLcLparticlelEfloatgRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<hep::particle<float> > : new vector<hep::particle<float> >;
   }
   static void *newArray_vectorlEhepcLcLparticlelEfloatgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<hep::particle<float> >[nElements] : new vector<hep::particle<float> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEhepcLcLparticlelEfloatgRsPgR(void *p) {
      delete ((vector<hep::particle<float> >*)p);
   }
   static void deleteArray_vectorlEhepcLcLparticlelEfloatgRsPgR(void *p) {
      delete [] ((vector<hep::particle<float> >*)p);
   }
   static void destruct_vectorlEhepcLcLparticlelEfloatgRsPgR(void *p) {
      typedef vector<hep::particle<float> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<hep::particle<float> >

namespace {
  void TriggerDictionaryInitialization_out_particle_Impl() {
    static const char* headers[] = {
"../hep_example/particle.hpp",
0
    };
    static const char* includePaths[] = {
"/Users/vk/software/root_home/build/include",
"/Users/vk/software/test-apache-arrow/scripts/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "out_particle dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace hep{template <typename T> struct __attribute__((annotate("$clingAutoload$../hep_example/particle.hpp")))  particle;
}
namespace std{inline namespace __1{template <class _Tp> class __attribute__((annotate("$clingAutoload$iosfwd")))  __attribute__((annotate("$clingAutoload$string")))  allocator;
}}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "out_particle dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "../hep_example/particle.hpp"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"hep::particle<float>", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("out_particle",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_out_particle_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_out_particle_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_out_particle() {
  TriggerDictionaryInitialization_out_particle_Impl();
}
