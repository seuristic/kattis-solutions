# kattis-solutions — agent instructions

Repo of Kattis solutions. Every solution lives in `solutions/<slug>.cpp` and has one
row in the `README.md` table.

## When asked to commit / push

1. `git status --short --untracked-files=all` and `git diff` to see what changed.
2. For every `solutions/<slug>.cpp` with no row in the `README.md` table — not just
   the newly added ones — read it, infer the algorithm/technique used, and append a
   row to the table in `README.md`:

   Find them with:

   ```
   for f in solutions/*.cpp; do s=$(basename "$f" .cpp); \
     grep -q "solutions/$s.cpp" README.md || echo "$s"; done
   ```

   ```
   | [<slug>](https://github.com/seuristic/kattis-solutions/blob/main/solutions/<slug>.cpp) | <approach> |
   ```

   - `<slug>` is the filename without `.cpp`, verbatim; it is also the link text.
   - Rows are appended at the end — the table is not sorted.
   - `<approach>` is a short lowercase technique list, comma-separated:
     `greedy, sorting`, `2D prefix sum`, `binary search`.

3. Format the table: `npx --yes prettier --write README.md`
   (this is what keeps the column padding aligned — don't hand-pad).
4. Stage everything and commit with a conventional commit message:
   - new solution(s): `feat: add solution for <slug>`
   - edits to existing solutions: `fix:` or `refactor:` as appropriate
   - README/structure only: `docs:` / `refactor:`
5. Push only if the user asked for it.

Non-solution files (`a.out`, `file.in`, `file.out`, `expected.out`) are scratch —
no README rows for them.
