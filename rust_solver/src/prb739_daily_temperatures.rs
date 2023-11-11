#![allow(dead_code)]
struct Solution;
impl Solution {
    pub fn daily_temperatures(temperatures: Vec<i32>) -> Vec<i32> {
        let mut result: Vec<i32> = vec![0; temperatures.len()];
        let mut stack: Vec<(usize, i32)> = Vec::new();
        temperatures
            .iter()
            .enumerate()
            .for_each(|(i, t)| {
                while !stack.is_empty() {
                    if let Some(tt) = stack.last() {
                        if *t > (*tt).1 {
                            let id = stack.pop().unwrap().0;
                            result[id] = (i - id) as i32;
                        }
                        else {
                            break;
                        }
                    }
                }
                stack.push((i, *t));
            });

        result
    }
}

#[test]
fn prb739_daily_temperatures()
{
    let i = Solution::daily_temperatures(vec![73,74,75,71,69,72,76,73]);
    let o: Vec<i32> = vec![1,1,4,2,1,1,0,0];
    assert_eq!(i, o);
    let i = Solution::daily_temperatures(vec![30,40,50,60]);
    let o: Vec<i32> = vec![1,1,1,0];
    assert_eq!(i, o);
    let i = Solution::daily_temperatures(vec![30,60,90]);
    let o: Vec<i32> = vec![1,1,0];
    assert_eq!(i, o);
}
/* 

   739. Daily Temperatures
   Medium
   Given an array of integers temperatures represents the daily temperatures,
   return an array answer such that answer[i] is the number of days you have 
   to wait after the ith day to get a warmer temperature. If there is no 
   future day for which this is possible, keep answer[i] == 0 instead.

   Example 1:
   Input: temperatures = [73,74,75,71,69,72,76,73]
   Output: [1,1,4,2,1,1,0,0]

   Example 2:
   Input: temperatures = [30,40,50,60]
   Output: [1,1,1,0]
   
   Example 3:
   Input: temperatures = [30,60,90]
   Output: [1,1,0]

   Constraints:
   1 <= temperatures.length <= 10^5
   30 <= temperatures[i] <= 100
*/
