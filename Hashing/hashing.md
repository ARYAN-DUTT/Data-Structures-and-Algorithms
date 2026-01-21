# Hashing
- Uses a hash function to map keys → indices
- Used to get faster searching of elements.

### Collisoion
- It happens when the place alloted by hash function is already occupied.

## Types of collision resolutions
1. Chaining or Open Hashing.
2. Open Addressing or Closed hashing.

## Types of closed hashing (Collision resolutions)
1. linear probing
2. Quadratic Probing
3. Double hashing

## Open hashing
- Uses linked list to add elements with same h(k) = k mod n.

## Linear Probing
- (h(k) + i)mod n
- Probe value is the no of times the vacancy had to be checked for an element.

## Quadratic Probing
- (h(k) + i^2)mod n.
- There is no Gourantee of finding a spot.

## Double hashing
- h1(k) = k Mod n.
- h2(k) = m - k mod m.
- n and m are co-prime
- ( h1(k) + i * h2(k) )mod n.