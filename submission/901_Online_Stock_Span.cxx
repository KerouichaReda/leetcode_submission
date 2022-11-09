#include <vector>

class StockSpanner {
   public:
    StockSpanner() {}

    int next(int price) {
        prices_.push_back(price);
        int temp{0};
        for (auto itr = prices_.rbegin(), end = prices_.rend();
             itr != end && *itr <= price; ++itr, temp++)
            ;
        return temp;
    }

   private:
    std::vector<int> prices_;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
