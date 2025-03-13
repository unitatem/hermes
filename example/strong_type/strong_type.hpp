#pragma once

#include <utility>

namespace details {
template <typename ValueT, typename TagT>
class StrongTypeBase {
public:
    using value_type = ValueT;

    constexpr StrongTypeBase(ValueT aData)
        : theData{std::forward<ValueT>(aData)} {}

    constexpr ValueT value() const { return theData; }

private:
    ValueT theData;
};
}  // namespace details

template <typename ValueT, typename TagT,
          template <typename> typename... PropertiesT>
struct StrongTypeFactory
    : public details::StrongTypeBase<ValueT, TagT>,
      public PropertiesT<StrongTypeFactory<ValueT, TagT, PropertiesT...>>... {
    using details::StrongTypeBase<ValueT, TagT>::StrongTypeBase;
};
