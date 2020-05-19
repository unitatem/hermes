#include <iostream>

#include "logger/logger.hpp"
#include "stock_data.hpp"
#include "stock_exchange_market.hpp"

int main()
{
    std::cout << "Hermes is running ..." << std::endl;

    hermes::StockExchangeMarket market;
    market.get_available_stock_exchange_markets();
}
