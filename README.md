# Clang-format Action Example

This is a minimal example showing how to use the [clang-format multi-version GitHub Action](https://github.com/pachadotdev/clang-format).

## What this example shows

- Automatic formatting of C++ code on push/PR
- Auto-commit formatted changes back to the repository
- Multiple workflow patterns for different use cases

## Files in this example

### Source Files

- `src/example.badformat` - C++ file with bad formatting
- `src/example.cpp` - auto-formatted copy of `src/example.badformat`
- `src/utils.badformat` - Header file with bad formatting
- `src/utils.h` - auto-formatted copy of `src/utils.badformat`
- `.clang-format` - Optional formatting style configuration (Google-based)

Note: the extension only modifies cpp and hpp files.

### GitHub Workflows

- `.github/workflows/format.yml` - ⭐ Minimal auto-format workflow (recommended)
- `.github/workflows/format-pr-check.yml` - PR validation workflow (check-only)
- `.github/workflows/format-specific.yml` - Manual workflow with version selection

## How it works

1. Push code with formatting issues
2. GitHub Action runs automatically
3. Code gets formatted with clang-format-18
4. Changes are committed back to the repository
5. No manual intervention needed!

## Try it yourself

1. Fork this repository
2. Make some changes to the C++ files with poor formatting
3. Add your own files and push your changes
4. Watch the action automatically format and commit the fixes

## Workflow Examples Explained

### `format.yml` - Minimal Auto-Formatting (⭐ Recommended)

What it does: Automatically formats and commits changes on every push/PR

```yaml
- uses: pachadotdev/clang-format@v1
  with:
    version: '18'
    auto-commit: true
    commit-message: 'style: auto-format C++ code with clang-format-18'
```

- ✅ Best for: Most projects wanting automatic code formatting
- 🔧 Behavior: Fixes code and commits back automatically
- 📝 Triggers: Every push to main/master/develop + PRs

### `format-pr-check.yml` - PR Validation Only

What it does: Checks formatting without making changes, fails if issues found
```yaml
- uses: pachadotdev/clang-format@v1
  with:
    version: '18'
    auto-commit: false
    fail-on-diff: true
```

- ✅ Best for: Enforcing code style in PRs without auto-fixing
- ❌ Behavior: Fails CI if formatting issues are detected
- 📝 Triggers: Only on pull requests

### `format-specific.yml` - Manual with Options

What it does: Manual workflow with version selection and specific file targeting

```yaml
- uses: pachadotdev/clang-format@v1
  with:
    version: ${{ github.event.inputs.clang_version }}
    files: 'src/*.cpp src/*.h'
    auto-commit: true
```

- ✅ Best for: Advanced users wanting control over when/how formatting runs
- 🎛️ Behavior: Choose clang-format version (11-19) via GitHub UI
- 📝 Triggers: Manual dispatch only (Actions tab → Run workflow)

## Quick Start Recommendation

For most projects, start with `format.yml`. It provides automatic formatting with minimal setup!

## Expected behavior

After pushing, you should see:

- ✅ Action runs successfully
- 🔧 Code gets properly formatted
- 📝 Automatic commit with formatted changes
- 🎉 Clean, consistent code style
