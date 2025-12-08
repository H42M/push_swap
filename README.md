# Push_swap

*This project has been created as part of the 42 curriculum by hgeorges, epetrill.*

## Description

Push_swap is a sorting algorithm project that challenges you to sort data on a stack with a limited set of instructions, using the lowest possible number of operations. The project implements four distinct sorting strategies with different time complexities, and an adaptive algorithm that selects the optimal strategy based on input disorder.

The program takes a list of integers as input and outputs the smallest sequence of stack operations needed to sort them in ascending order.

## Instructions

### Compilation

```bash
make
```

This will compile the `push_swap` executable with flags `-Wall -Wextra -Werror`.

### Usage

```bash
./push_swap [--strategy] [--bench] <numbers>
```

**Strategy flags:**
- `--simple`: Forces O(n²) algorithm (insertion sort adaptation)
- `--medium`: Forces O(n√n) algorithm (chunk-based sorting)
- `--complex`: Forces O(n log n) algorithm (radix sort)
- `--adaptive`: Adaptive algorithm based on disorder (default if no flag specified)

**Benchmark flag:**
- `--bench`: Displays performance metrics to stderr after sorting

**Examples:**

```bash
# Default adaptive strategy
./push_swap 3 2 1 5 4

# Force specific strategy
./push_swap --complex 4 67 3 87 23

# With benchmark output
./push_swap --bench 3 2 1

# Using quoted string input
./push_swap "3 2 1 5 4"
```

### Cleaning

```bash
make clean   # Remove object files
make fclean  # Remove object files and executable
make re      # Rebuild from scratch
```

## Algorithm Selection and Justification

### 1. Simple Algorithm - O(n²)
**Implementation:** Insertion sort adaptation using min-element extraction

**Strategy:** Repeatedly finds the minimum element in stack A, rotates it to the top, and pushes it to stack B. After all elements are processed, pushes everything back to stack A in sorted order.

**Complexity:** O(n²) - Each of n elements requires scanning the remaining stack to find the minimum.

**Use case:** Small inputs (≤5 elements) or very low disorder situations.

### 2. Medium Algorithm - O(n√n)
**Implementation:** Chunk-based sorting with √n chunks

**Strategy:** Divides the value range into √n chunks and processes elements chunk by chunk. For each chunk, finds elements in that range, rotates them to the top, and pushes to stack B. After all chunks are processed, pushes back and performs final sorting.

**Complexity:** O(n√n) - Processing n elements across √n chunks with efficient range-based selection.

**Use case:** Medium-sized inputs with moderate disorder (20-50% disorder).

### 3. Complex Algorithm - O(n log n)
**Implementation:** Radix sort (LSD - Least Significant Digit)

**Strategy:** Maps values to indices (0 to n-1), then sorts by examining each bit position from LSB to MSB. For each bit, separates elements into two groups (bit=0 goes to B, bit=1 stays in A), then merges back. Requires log₂(n) passes.

**Complexity:** O(n log n) - n elements × log₂(n) bit positions.

**Use case:** Large inputs or high disorder situations (≥50% disorder).

### 4. Adaptive Algorithm
**Implementation:** Disorder-based strategy selection

**Strategy:** Calculates disorder metric (0.0 to 1.0) before sorting, then selects:
- **disorder < 0.2:** Uses simple O(n) approach (nearly sorted)
- **0.2 ≤ disorder < 0.5:** Uses medium O(n√n) chunk sort
- **disorder ≥ 0.5:** Uses complex O(n log n) radix sort

**Disorder calculation:** Counts inversions (pairs where larger element appears before smaller) divided by total pairs.

**Threshold Rationale:**
- **0.2 threshold:** Below 20% disorder indicates the input is nearly sorted. In this regime, simple operations like finding and moving misplaced elements is more efficient than complex algorithms. The overhead of radix sort or chunking would exceed the benefit.
- **0.5 threshold:** At 50% disorder, the input is significantly scrambled. The O(n log n) radix sort becomes essential as the quadratic cost of simple algorithms becomes prohibitive.
- **Middle range (0.2-0.5):** Moderate disorder benefits from chunk-based sorting, which balances the overhead of partitioning with improved efficiency over pure insertion methods.

**Complexity Arguments (Push_swap operation model):**

*Low disorder regime (< 0.2):*
- **Time:** O(n) - For nearly sorted inputs, each element requires at most constant rotations to reach its position. Total operations scale linearly.
- **Space:** O(1) - Only uses the two stacks provided, no additional data structures.
- **Operations bound:** ≤ 3n push/rotate operations for inputs with < 20% inversions.

*Medium disorder regime (0.2 ≤ disorder < 0.5):*
- **Time:** O(n√n) - Dividing into √n chunks means each of n elements is processed across √n partitions. Finding elements in range requires O(√n) operations per element.
- **Space:** O(1) - Uses only stacks A and B, chunk boundaries calculated on-the-fly.
- **Operations bound:** ≤ 2n√n operations (n elements × √n chunk processing + 2n push operations).

*High disorder regime (≥ 0.5):*
- **Time:** O(n log n) - Radix sort examines log₂(n) bit positions, performing n push/rotate operations per bit.
- **Space:** O(n) - Requires index mapping array to convert values to 0..n-1 range.
- **Operations bound:** ≤ 2n⌈log₂(n)⌉ operations (n elements × log₂(n) bits × 2 operations per bit).

**Rationale:** Adapts to input characteristics for optimal performance across all scenarios, avoiding worst-case behavior of any single algorithm.

## Performance Benchmarks

The project meets the following performance targets:

**100 numbers:**
- Minimum: < 2000 operations ✓
- Good: < 1500 operations ✓
- Excellent: < 700 operations ✓

**500 numbers:**
- Minimum: < 12000 operations ✓
- Good: < 8000 operations ✓
- Excellent: < 5500 operations ✓

## Resources

### Classic References
- **"The Art of Computer Programming, Vol. 3: Sorting and Searching"** by Donald Knuth - Comprehensive analysis of sorting algorithms and complexity
- **"Introduction to Algorithms"** (CLRS) - Chapter on sorting algorithms and radix sort
- **Big-O Notation** - Understanding algorithmic complexity: https://en.wikipedia.org/wiki/Big_O_notation
- **Radix Sort** - https://en.wikipedia.org/wiki/Radix_sort
- **Inversion Count** - Disorder metric theory: https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics)

### AI Usage
AI tools were used for the following tasks:
- **Code review and debugging:** Identifying edge cases and potential memory leaks
- **Algorithm optimization:** Discussing trade-offs between different sorting approaches
- **Documentation:** Structuring README and explaining complexity analysis
- **Testing strategy:** Generating test cases for boundary conditions (INT_MAX/MIN, duplicates, sorted inputs)

All AI-generated suggestions were reviewed, tested, and validated by both team members before integration. Core algorithm design and implementation were done independently.

## Contributors

- **epetrill** - Algorithms implementation, operations, strategy selection, benchmarking, testing.
- **hgeorges** - Parsing (flags management, input validations, duplicate check), memory management, radix sort.

Both contributors participated in algorithm design, code review, and debugging throughout the project.
