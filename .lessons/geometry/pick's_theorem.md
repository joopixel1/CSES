### Pick's Theorem

#### Introduction

Pick's Theorem is a geometric formula that provides a relationship between the area of a simple lattice polygon (a polygon whose vertices are points on a lattice) and the number of lattice points inside it and on its boundary. It was discovered by Georg Alexander Pick in 1899.

#### Statement of Pick's Theorem

For a simple polygon whose vertices lie on the integer lattice points in the plane, the area \( A \) of the polygon can be determined using the formula:

\[ A = I + \frac{B}{2} - 1 \]

where:
- \( I \) is the number of lattice points strictly inside the polygon.
- \( B \) is the number of lattice points on the boundary of the polygon.

#### Proof of Pick's Theorem

The proof of Pick's Theorem involves several key steps, often using induction and basic properties of lattice points and polygons. Here's a sketch of the proof:

1. **Base Case:**
   - Consider the smallest possible polygon, a triangle.
   - For a lattice triangle, Pick's Theorem simplifies to \( A = I + \frac{B}{2} - 1 \).

2. **Induction Step:**
   - Assume Pick's Theorem holds for a simple lattice polygon with \( n \) vertices.
   - Show it holds for a polygon with \( n + 1 \) vertices by adding a new vertex and splitting the polygon into smaller ones.

3. **Elementary Shapes:**
   - Triangles and parallelograms (rectangles) are considered elementary shapes.
   - For these shapes, the formula is easier to verify directly using basic geometric properties.

4. **Additivity of Area:**
   - The area of a polygon can be decomposed into the sum of areas of non-overlapping triangles and parallelograms.
   - By verifying the formula for these elementary shapes, one can extend the result to more complex polygons.

#### Side Proof: Formula for Finding \( B \)

The number of boundary lattice points \( B \) on the edges of a lattice polygon can be found using the greatest common divisor (GCD) of the differences in the coordinates of the endpoints of each edge.

For an edge with endpoints \((x_1, y_1)\) and \((x_2, y_2)\):
- The number of lattice points on the boundary of the edge, including the endpoints, is given by:
  \[
  \text{GCD}(|x_2 - x_1|, |y_2 - y_1|) + 1
  \]
- Subtract 1 to avoid double-counting the endpoints when calculating \( B \) for the whole polygon.

**Proof:**
1. **Collinear Points:**
   - The line segment between \((x_1, y_1)\) and \((x_2, y_2)\) contains lattice points if and only if the points are collinear and equally spaced.
   - The spacing between points on the segment can be described by the integer steps along \( x \) and \( y \).

2. **Steps Between Points:**
   - The number of steps required to move from \((x_1, y_1)\) to \((x_2, y_2)\) along the lattice grid is determined by the GCD of the differences in coordinates.
   - This is because the GCD represents the largest integer step size that fits exactly into both \( |x_2 - x_1| \) and \( |y_2 - y_1| \).

3. **Counting Lattice Points:**
   - Each step includes both endpoints, so we add 1 to the GCD to account for the lattice points on the segment.

**Example Calculation:**
- For a segment from \((0, 0)\) to \((4, 6)\):
  \[
  B = \text{GCD}(4, 6) + 1 = 2 + 1 = 3
  \]

#### Detailed Proof

1. **Triangles:**
   - For any triangle with vertices on the lattice points, the area can be calculated using the Shoelace formula.
   - Verify that the formula \( A = I + \frac{B}{2} - 1 \) holds by directly counting the lattice points.

2. **Rectangles:**
   - For a rectangle with sides aligned to the axes, the area is given by \( A = l \times w \) where \( l \) and \( w \) are the side lengths.
   - Count the interior and boundary lattice points and verify that \( A = I + \frac{B}{2} - 1 \).

3. **General Polygons:**
   - For a general simple polygon, decompose it into triangles and rectangles.
   - Use the additivity of area and the fact that Pick's Theorem holds for these elementary shapes to extend it to the entire polygon.

#### Examples

1. **Example 1: Triangle**
   - Consider a triangle with vertices at (0,0), (4,0), and (0,3).
   - \( I = 1 \) (the point (1,1)).
   - \( B = 9 \) (points on the boundary: (0,0), (4,0), (0,3), (1,0), (2,0), (3,0), (0,1), (0,2)).
   - Using Pick's Theorem: \( A = 1 + \frac{9}{2} - 1 = 1 + 4.5 - 1 = 4.5 \).
   - The area calculated using the Shoelace formula is also 4.5.

2. **Example 2: Rectangle**
   - Consider a rectangle with vertices at (0,0), (4,0), (4,3), and (0,3).
   - \( I = 6 \) (points strictly inside: (1,1), (2,1), (3,1), (1,2), (2,2), (3,2)).
   - \( B = 10 \) (points on the boundary: (0,0), (4,0), (4,3), (0,3), (1,0), (2,0), (3,0), (0,1), (0,2), (4,1), (4,2), (0,2), (0,3)).
   - Using Pick's Theorem: \( A = 6 + \frac{10}{2} - 1 = 6 + 5 - 1 = 10 \).
   - The area calculated using the formula for a rectangle is also 12.

#### Conclusion

Pick's Theorem provides a powerful and elegant way to relate the geometric properties of lattice polygons to their combinatorial properties. It is a beautiful example of how discrete mathematics and geometry intersect, offering insights and tools for both theoretical investigations and practical applications.