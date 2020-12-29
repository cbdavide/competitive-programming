
countOcc :: [Integer] -> Integer -> Integer
countOcc list n = sum [ 1 | x <- list, x == n]

solve :: [Integer] -> Integer -> Integer -> Integer
solve list x y
    | x == y    = div (n * (n - 1)) 2
    | otherwise = (countOcc list x) * (countOcc list y)
    where n = toInteger (length list)


main :: IO ()
main = do
    n <- getLine
    strNums <- getLine
    let nums = [ read x :: Integer | x <- (words strNums)]
        mx = maximum nums
        mn = minimum nums
    putStrLn $ (show (mx - mn)) ++ " " ++ (show (solve nums mx mn))
