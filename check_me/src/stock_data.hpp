#ifndef JASON_STOCK_DATA_HPP
#define JASON_STOCK_DATA_HPP

#include <vector>

namespace hermes
{

struct StockDayData
{
    double min_price;
    double max_price;
    double avg_price;

    std::string date;
};

struct StockData
{
    std::vector<StockDayData> history;
};

} // namespace hermes

#endif // JASON_STOCK_DATA_HPP
