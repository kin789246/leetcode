#![allow(dead_code)]

struct Solution;

impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut max: i32 = 0;
        let mut i = 0;
        let mut j = i + 1;
        while j < prices.len() && i < prices.len() {
            if prices[j] >= prices[i] {
                max = std::cmp::max(prices[j] - prices[i], max);
                j += 1;
            }
            else {
                i += 1;
            }
        }
        max
    }
}

#[test]
fn prb121()
{
    let p1 = vec![7, 1, 5, 3, 6, 4];
    let o1 = 5;
    let p2 = vec![7, 6, 4, 3, 1];
    let o2 = 0;
    let p3 = vec![1,2,4,2,5,7,2,4,9,0,9];
    let o3 = 9;
    assert_eq!(o1, Solution::max_profit(p1));
    assert_eq!(o2, Solution::max_profit(p2));
    assert_eq!(o3, Solution::max_profit(p3));
}
