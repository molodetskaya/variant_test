#include <benchmark/benchmark.h>

#include <boost/variant.hpp>

#include <iostream>
#include <string>
#include <variant>

struct point
{
    int a;
    int b;
};

struct VisitPackageBoost : public boost::static_visitor<>
{
  void operator()( double d ) const { ; }
  void operator()( char c ) const { ; }
  void operator()( std::string s ) const { ; }
  void operator()( bool b ) const { ; }
  void operator()( int i ) const { ; }
  void operator()( point p ) const { ; }
};

struct VisitPackageStd
{
  void operator()( double d ) const { ; }
  void operator()( char c ) const { ; }
  void operator()( std::string s ) const { ; }
  void operator()( bool b ) const { ; }
  void operator()( int i ) const { ; }
  void operator()( point p ) const { ; }
};

static void StdVariantRef( std::variant<double, char, std::string, bool, int, point> & v ) {
    VisitPackageStd visitor;
    std::visit( visitor, v );
}

static void StdVariantRefTest( benchmark::State& state ) {
    for ( auto _ : state ) {
        std::variant<double, char, std::string, bool, int, point> v;
        v = 9.45;
        StdVariantRef( v );
        v = 'V';
        StdVariantRef( v );
        v = "test";
        StdVariantRef( v );
        v = true;
        StdVariantRef( v );
        v = 1;
        StdVariantRef( v );
        v = point{1, 1};
        StdVariantRef( v );
    }
    std::cout <<std::endl;
}
BENCHMARK( StdVariantRefTest );

static void StdVariantCopy( std::variant<double, char, std::string, bool, int, point> v ) {
    VisitPackageStd visitor;
    std::visit( visitor, v );
}

static void StdVariantCopyTest( benchmark::State& state ) {
    for ( auto _ : state ) {
        std::variant<double, char, std::string, bool, int, point> v;
        v = 9.45;
        StdVariantCopy( v );
        v = 'V';
        StdVariantCopy( v );
        v = "test";
        StdVariantCopy( v );
        v = true;
        StdVariantCopy( v );
        v = 1;
        StdVariantCopy( v );
        v = point{1, 1};
        StdVariantCopy( v );
    }
    std::cout <<std::endl;
}
BENCHMARK( StdVariantCopyTest );

static void StdVariantTest( benchmark::State& state ) {
    for ( auto _ : state ) {
        VisitPackageStd visitor;
        std::variant<double, char, std::string, bool, int, point> v;
        v = 9.45;
        std::visit( visitor, v );
        v = 'V';
        std::visit( visitor, v );
        v = "test";
        std::visit( visitor, v );
        v = true;
        std::visit( visitor, v );
        v = 1;
        std::visit( visitor, v );
        v = point{1, 1};
        std::visit( visitor, v );
    }
    std::cout <<std::endl;
}
BENCHMARK( StdVariantTest );

static void BoostVariantRef( boost::variant<double, char, std::string, bool, int, point> & v ) {
    VisitPackageBoost visitor;
    boost::apply_visitor( visitor, v );
}

static void BoostVariantRefTest( benchmark::State& state ) {
    for ( auto _ : state ) {
        boost::variant<double, char, std::string, bool, int, point> v;
        v = 9.45;
        BoostVariantRef( v );
        v = 'V';
        BoostVariantRef( v );
        v = "test";
        BoostVariantRef( v );
        v = true;
        BoostVariantRef( v );
        v = 1;
        BoostVariantRef( v );
        v = point{1, 1};
        BoostVariantRef( v );
    }
    std::cout <<std::endl;
}
BENCHMARK( BoostVariantRefTest );

static void BoostVariantCopy( boost::variant<double, char, std::string, bool, int, point> v ) {
    VisitPackageBoost visitor;
    boost::apply_visitor( visitor, v );
}

static void BoostVariantCopyTest( benchmark::State& state ) {
    for ( auto _ : state ) {
        boost::variant<double, char, std::string, bool, int, point> v;
        v = 9.45;
        BoostVariantCopy( v );
        v = 'V';
        BoostVariantCopy( v );
        v = "test";
        BoostVariantCopy( v );
        v = true;
        BoostVariantCopy( v );
        v = 1;
        BoostVariantCopy( v );
        v = point{1, 1};
        BoostVariantCopy( v );
    }
    std::cout <<std::endl;
}
BENCHMARK( BoostVariantCopyTest );

static void BoostVariantTest( benchmark::State& state ) {
    for ( auto _ : state ) {
        VisitPackageBoost visitor;
        boost::variant<double, char, std::string, bool, int, point> v;
        v = 9.45;
        boost::apply_visitor( visitor, v );
        v = 'V';
        boost::apply_visitor( visitor, v );
        v = "test";
        boost::apply_visitor( visitor, v );
        v = true;
        boost::apply_visitor( visitor, v );
        v = 1;
        boost::apply_visitor( visitor, v );
        v = point{1, 1};
        boost::apply_visitor( visitor, v );
    }
    std::cout <<std::endl;
}
BENCHMARK( BoostVariantTest );

BENCHMARK_MAIN();