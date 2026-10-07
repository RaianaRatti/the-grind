/*
PB1.79 Market Maker
Assume you are a market maker in an electronic stock exchange. You are given a stream of stock
data which includes an identifier (a unique abbreviation that identifies the stock), the highest price
that a buyer is willing to pay for the stock, and the lowest price that a seller is willing to sell the
stock for. Each stock will only appear once in the stream and will have exactly one buyer and one
seller.

The difference between the buyer and seller prices (i.e. buyer price−seller price) is the amount
of money you earn from participating in the transaction. For instance, if a buyer is looking to buy
EECS stock at $10 and a seller is offering EECS stock for $7, you can make a profit of $10−$7 = $3.
If buyer price−seller price for a stock is negative, that stock should be ignored, as
you would lose money if you tried to force a transaction!

You will implement the max profit function, which takes in a stream of stock information
stock in and a positive integer k. The function returns the maximum profit you can
make from trading at most k stocks from the entire stream. It is possible for fewer than
k transactions to occur, since not all stock transactions may produce positive profits (see Example
2). The stock in stream will contain data for a total of n stocks in the following format:

<stock id1> <buy price1> <sell price1> <stock id2> <buy price2> <sell price2> ...
<stock idn> <buy pricen> <sell pricen>

Constraints:
Your solution should run in at most Θ(n log k) time, where n is the number of stocks in the
stream. The value of n will NOT be given to you.
Your solution should use at most Θ(k) space.
You may assume that 0 < k ≤n.

Your solution should NOT make use of custom-defined structs or classes.

Hint: The stock in stream behaves like cin, and its contents can be extracted using operator>>.
For example: stock in >> stock id >> buy price >> sell price;

Example 1: k = 3, stream EECS 5.00 2.00 BBB 81.00 79.00 IOE 42.50 42.00 EWRE 20.53
15.53 GGBL 22.15 21.15 returns 10.00 (EECS $3, BBB $2, EWRE $5).

Example 2: k = 5, stream DOW 14.41 12.41 COOL 45.19 46.83 LBME 16.63 16.61 FXB
3.14 8.11 NAME 12.79 12.00 returns 2.81 (DOW $2, LBME $0.02, NAME $0.79; COOL and
FXB have negative profit and are skipped).

Complexity: At most Θ(n log k) time and Θ(k) space.

Implementation: Limit: 25 lines of code (points deducted if longer). You MAY use anything
in the STL.
*/

#include <iostream>
#include <map>

using namespace std;

double max_profit(istream &stock_in, int k) {
    string stock_id;
    double buy_price;
    double sell_price;

    map<double, string> map; // {profit, identity} - smallest to largest
    double total_profit = 0;

    while (stock_in >> stock_id >> buy_price >> sell_price) {
        double profit = buy_price - sell_price;

        // Skip if profit is negative
        if (profit < 0) {
            continue;
        }

        // Insert this new element if larger than map[0] and map.size() == k
        auto smallest = map.begin();

        if (map.size() < k) { 
            map[profit] = stock_id; 
            total_profit += profit;
        }
        else if (profit > smallest->first) {
            total_profit -= smallest->first;

            map.erase(smallest);
            map[profit] = stock_id;

            total_profit += profit;
        }
    }

    return total_profit;
}