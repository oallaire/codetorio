#include <spdlog/spdlog.h>

class Foo {
public:
    int i;

    Foo(int i) : i(i) {}
};

template<>
struct fmt::formatter<Foo> : fmt::formatter<std::string>
{
    auto format(Foo my, format_context &ctx) const -> decltype(ctx.out())
    {
        return fmt::format_to(ctx.out(), "[my_type i={}]", my.i);
    }
};

class IBar {
public:
    virtual ~IBar() = default;

    virtual int getJ() const = 0;
};

class Bar : public IBar {
public:
    int j;

    Bar(int j) : j(j) {}

    int getJ() const override {
        return j;
    }
};

template<>
struct fmt::formatter<IBar> : fmt::formatter<std::string>
{
    auto format(const IBar &my, format_context &ctx) const -> decltype(ctx.out())
    {
        return fmt::format_to(ctx.out(), "[my_type i={}]", my.getJ());
    }
};

template<>
struct fmt::formatter<Bar> : fmt::formatter<std::string>
{
    auto format(Bar my, format_context &ctx) const -> decltype(ctx.out())
    {
        return fmt::format_to(ctx.out(), "[my_type i={}]", my.j);
    }
};

int main() {
    spdlog::info("spdlog_poc");

    Foo foo(0);
    spdlog::info("Foo: {}", foo);

    auto fp = std::make_shared<Foo>(1);
    spdlog::info("Foo: {}", *fp);

    Bar bar(2);
    spdlog::info("Bar: {}", bar);

    std::shared_ptr<IBar> fb = std::make_shared<Bar>(3);
    spdlog::info("Bar: {}", *fb);

    return 0;
}
