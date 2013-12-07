-- No IO, use ghci to test this

eulerTotient :: Integer -> Int
eulerTotient n = length [i | i <- [1..n-1], coprime n i]

coprime :: Integer -> Integer -> Bool
coprime a b = euclid a b == 1

euclid :: Integer -> Integer -> Integer
euclid a b 
	| b == 0 = a
	| otherwise = euclid b (mod a b)
