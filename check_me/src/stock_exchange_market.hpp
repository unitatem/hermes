#ifndef JASON_STOCK_EXCHANGE_MARKET_HPP
#define JASON_STOCK_EXCHANGE_MARKET_HPP

#include <string>
#include <vector>

#include "stock_data.hpp"

namespace hermes
{

class StockExchangeMarket
{
public:
    std::vector<std::string> get_available_stock_exchange_markets() const;
    std::vector<std::string> get_stocks(const std::string& stock_exchange_market) const;
    StockData get_stock_data(const std::string& stock) const;
};

} // namespace hermes

#endif // JASON_STOCK_EXCHANGE_MARKET_HPP
