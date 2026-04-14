# 15-445/645 C++ 부트캠프
이 부트캠프는 현대적인 C++(modern C++)로 코드를 작성하는 데 필요한 기초를 소개하는 것을 목표로 합니다. 
C++ 언어의 기능은 너무 방대해서 한 번의 부트캠프에서 모두 다루기 어렵고,
솔직히 말해 많은 부분은 직접 경험하면서 배우는 것이 가장 좋습니다. 수업 스태프는
15-445가 여러분을 더 자신감 있는 C++ 프로그래머로 만들어 줄 것이라 확신합니다! 
다만 프로그래밍 과제를 수행하면서 반드시 알아야 하는 몇 가지 C++ 주제는 이 부트캠프에서 다룹니다.
이 튜토리얼은 기본적인 C/C++ 문법은 다루지 않습니다.
주로 C에는 없는 C++의 기능들, 특히 C와 구별되는 현대 C++(modern C++) 개념을 중심으로 설명합니다.

C++ 부트캠프에 대한 피드백은 언제나 환영합니다! 이슈나 PR을 자유롭게 제출해 주세요.

## 형식
이 부트캠프는 `src/`에 있는 C++ 코드 파일들로 구성되어 있으며,
각 파일은 꼼꼼하게 읽어 보는 것을 전제로 작성되었습니다. 각 파일은 동일한 이름의
실행 파일(executable)로 컴파일할 수 있습니다. 이 실행 파일들은 CMake를 사용해 빌드합니다.
아래 명령어를 실행하면 모든 실행 파일을 빌드할 수 있습니다.
명령 실행이 끝나면 실행 파일들은 `build` 디렉터리에 생성됩니다.
```console
$ mkdir build
$ cd build
$ cmake ..
$ make -j8
```
예를 들어 `src/references.cpp` 파일은 `references` 실행 파일(executable)로 컴파일되며,
이 파일은 `./build`에 생성됩니다. 소스 디렉터리의 다른 파일들도 모두 같은 방식으로 동작합니다.

## 파일
`src/` 디렉터리에는 서로 다른 개념을 다루는 열다섯 개의 파일이 있습니다.
각 파일은 이전 내용을 바탕으로 이어지므로 아래 순서대로 읽는 것을 권장합니다.
다만 현대 C++(modern C++) 개념을 어느 정도 알고 있고 복습이 목적이라면,
익숙하지 않은 개념의 파일부터 읽어도 괜찮습니다.

### 참조(References)와 이동 시맨틱(Move Semantics)
- `references.cpp`: C++ 참조를 다룹니다.
- `move_semantics.cpp`: C++ 이동 시맨틱(move semantics)을 다룹니다.
- `move_constructors.cpp`: C++ 클래스의 이동 생성자(move constructors)와 이동 대입 연산자(move assignment operators)를 다룹니다.

### C++ 템플릿(Templates)
- `templated_functions.cpp`: C++ 템플릿 함수(templated functions)를 다룹니다.
- `templated_classes.cpp`: C++ 템플릿 클래스(templated classes)를 다룹니다.

### 기타
- `wrapper_class.cpp`: C++ 래퍼 클래스(wrapper class)를 다룹니다.
- `iterator.cpp`: 기본적인 C++ 스타일 반복자(iterator)를 구현하는 방법을 다룹니다.
- `namespaces.cpp`: C++ 네임스페이스(namespace)를 다룹니다.

### C++ 표준 라이브러리(STL) 컨테이너(Containers)
- `vectors.cpp`: `std::vector`를 다룹니다.
- `set.cpp`: `std::set`을 다룹니다.
- `unordered_map.cpp`: `std::unordered_map`을 다룹니다.
- `auto.cpp`: C++ 키워드 `auto`의 사용법을 다루며, `auto`를 사용해 C++ STL 컨테이너(container)를 순회하는 방법도 포함합니다.

### C++ 표준 라이브러리(STL) 메모리(Memory)
- `unique_ptr.cpp`: `std::unique_ptr`를 다룹니다.
- `shared_ptr.cpp`: `std::shared_ptr`를 다룹니다.

### C++ 표준 라이브러리(STL) 동기화 프리미티브(Synchronization Primitives)
- `mutex.cpp`: `std::mutex`를 다룹니다.
- `scoped_lock.cpp`: `std::scoped_lock`을 다룹니다.
- `condition_variable.cpp`: `std::condition_variable`을 다룹니다.
- `rwlock.cpp`: 여러 C++ STL 동기화 프리미티브(synchronization primitive) 라이브러리(`std::shared_mutex`, `std::shared_lock`, `std::unique_lock`)를 활용해 읽기-쓰기 락(reader-writer lock) 구현을 만드는 방법을 다룹니다.

### 15-445/645 부트캠프 데모 코드(Demo Code)
- `spring2024/s24_my_ptr.cpp`: 2024년 봄학기 부트캠프에서 사용한 코드(code)를 다룹니다.

## 기타 자료
C++에 익숙해지는 동안 도움이 될 만한 자료는 아주 많습니다.
그중 몇 가지를 아래에 정리했습니다!
- [https://en.cppreference.com/w/](https://en.cppreference.com/w/): 비공식 자료이지만 C++와 C 표준에 대한 요약과 예제가 꽤 정확하게 정리되어 있습니다.
- [https://cplusplus.com/](https://cplusplus.com/): C++ 언어 [튜토리얼(tutorial)](https://cplusplus.com/doc/tutorial/)과 C++ 라이브러리 [레퍼런스(reference)](https://cplusplus.com/reference/)를 모두 제공합니다.
- [Modern C++ Tutorial](https://github.com/changkun/modern-cpp-tutorial): 유용한 설명과 연습 문제가 포함된 GitHub 저장소입니다.

## 부록: 부트캠프에서 다룬 주제에 대한 C++ 문서
이 문서는 여러분에게 유용할 수 있습니다! 매우 포괄적이지만(이 부트캠프보다 훨씬 더 포괄적입니다)
가독성은 다소 떨어질 수 있습니다. 그래도 특히 프로젝트를 진행할 때는
이 문서를 직접 읽고 이해하려고 노력해 보는 것이 좋다고 생각합니다.
이 부트캠프는 가능한 한 폭넓게 다루려고 하지만,
현대 C++ 사용법의 가장 기초적인 부분만 다룬다는 점을 기억해 주세요.

- [참조(References)](https://en.cppreference.com/w/cpp/language/reference)
- [std::move](https://en.cppreference.com/w/cpp/utility/move)
- [이동 생성자(Move Constructors)](https://en.cppreference.com/w/cpp/language/move_constructor) 및 [이동 대입 연산자(Move Assignment Operators)](https://en.cppreference.com/w/cpp/language/move_assignment)
- [템플릿 함수(Templated Functions)](https://en.cppreference.com/w/cpp/language/function_template)
- [템플릿 클래스(Templated Classes)](https://en.cppreference.com/w/cpp/language/class_template)
- [반복자(Iterators)](https://en.cppreference.com/w/cpp/iterator)
- [네임스페이스(Namespaces)](https://en.cppreference.com/w/cpp/language/namespace)
- [std::vector](https://en.cppreference.com/w/cpp/container/vector)
- [std::set](https://en.cppreference.com/w/cpp/container/set)
- [std::unordered_map](https://en.cppreference.com/w/cpp/container/unordered_map)
- [auto](https://en.cppreference.com/w/cpp/language/auto)
- [std::unique_ptr](https://en.cppreference.com/w/cpp/memory/unique_ptr)
- [std::shared_ptr](https://en.cppreference.com/w/cpp/memory/shared_ptr)
- [std::mutex](https://en.cppreference.com/w/cpp/thread/mutex)
- [std::scoped_lock](https://en.cppreference.com/w/cpp/thread/scoped_lock)
- [std::condition_variable](https://en.cppreference.com/w/cpp/thread/condition_variable)
- [std::shared_mutex](https://en.cppreference.com/w/cpp/thread/shared_mutex)
- [std::shared_lock](https://en.cppreference.com/w/cpp/thread/shared_lock)
- [std::unique_lock](https://en.cppreference.com/w/cpp/thread/unique_lock)
