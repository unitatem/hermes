#include "stock_exchange_market.hpp"

#include "logger/logger.hpp"

namespace hermes
{

std::vector<std::string> StockExchangeMarket::get_available_stock_exchange_markets() const
{
    LOG_START();
    LOG_END();
    return {};
}

std::vector<std::string> StockExchangeMarket::get_stocks(const std::string& stock_exchange_market) const
{
    (void) stock_exchange_market;
    return {};
}

StockData StockExchangeMarket::get_stock_data(const std::string& stock) const
{
    (void) stock;
    return {};
}

} // namespace hermes
