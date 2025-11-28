
# Linux Commands Practice – README

This README walks through all the exercises and example commands from the **linux commands** practice sheet.:contentReference[oaicite:0]{index=0}  
You can follow it step-by-step in a fresh terminal session.

---

## 1. Directory Navigation & Creation

### 1. Display the path of your current directory

```bash
pwd
````

---

### 2. Make a new directory named `main`

```bash
mkdir main
```

---

### 3. Change to the directory `main`

```bash
cd main
```

---

### 4. Create a directory hierarchy `Dir1/Dir2/Dir3` using a single command

```bash
mkdir -p Dir1/Dir2/Dir3
```

---

### 5. Print the path of the current directory

```bash
pwd
```

---

### 6. Go directly to `Dir3` using a single command

Assuming you are *not* already inside `Dir1`:

```bash
cd main/Dir1/Dir2/Dir3
```

If you are already in `main`:

```bash
cd Dir1/Dir2/Dir3
```

---

## 2. Creating & Editing Text Files

All of these are intended to be done inside `Dir3`.

### 7. Create `demo1` with the content:

> This is my first file in shell.

Using `echo`:

```bash
echo "This is my first file in shell." > demo1.txt
```

(You could also use a text editor such as `nano demo1.txt`.)

---

### 8. Create `demo2` with multiple lines:

```text
Hi !!! This is the second file.
I am doing shell commands.
I can edit this file!!!
```

Using `nano`:

```bash
nano demo2.txt
# Type the 3 lines, then save and exit.
```

Or with a single `cat` command:

```bash
cat > demo2.txt << 'EOF'
Hi !!! This is the second file.
I am doing shell commands.
I can edit this file!!!
EOF
```

---

### 9. Display the contents of `demo1` in the terminal

```bash
cat demo1.txt
```

---

### 10. List the files and folders present in `Dir3`

From anywhere:

```bash
ls -lah ~/main/Dir1/Dir2/Dir3
```

If you are already in `Dir3`:

```bash
ls -lah
```

---

### 11. Go to `Dir2`

From `Dir3`:

```bash
cd ..
```

If you are elsewhere:

```bash
cd ~/main/Dir1/Dir2
```

---

### 12. Go to your home directory

```bash
cd ~
```

---

### 13. Stay in your home directory and list the contents of `Dir3`

```bash
ls -l ~/main/Dir1/Dir2/Dir3
```

---

### 14. List **all** files (including hidden) in your home directory

```bash
ls -lah ~
```

---

## 3. Copying, Renaming & Moving Files

### 15. Create `test1` with the content:

```text
I am working with linux shell.
Good bye
```

One way:

```bash
cd ~
cat > test1.txt << 'EOF'
I am working with linux shell.
Good bye
EOF
```

---

### 16. Copy the contents of `test1` to `test2` in the same directory

```bash
cp test1.txt test2.txt
```

To verify:

```bash
diff test1.txt test2.txt
```

---

### 17. Rename `test2` as `test3`

```bash
mv test2.txt test3.txt
```

---

### 18. Determine the file type of `test3`

```bash
file test3.txt
```

---

### 19. Move the file `test3` to directory `Dir3`

```bash
mv test3.txt ~/main/Dir1/Dir2/Dir3/
```

---

## 4. Creating Number Files (`count`, `count2`, `count3`, `countfinal`)

### 20. Create `count` with the words “one” to “twenty”, one per line, using a single command

Example with `printf`:

```bash
printf "%s\n" \
one two three four five six seven eight nine ten \
eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen twenty \
> count.txt
```

---

### 21. Copy the file `count` to `count2` using `cat`

```bash
cat count.txt > count2.txt
```

---

### 22. Create `count3` with the words “twenty one” to “twenty five”

```bash
printf "%s\n" \
"twenty one" "twenty two" "twenty three" "twenty four" "twenty five" \
> count3.txt
```

---

### 23. (Implied) Create `countfinal` by concatenating the three files

```bash
cat count.txt count2.txt count3.txt > countfinal.txt
```

---

### 24. Remove the files `demo1` and `demo2` in `Dir3`

```bash
rm ~/main/Dir1/Dir2/Dir3/demo1.txt ~/main/Dir1/Dir2/Dir3/demo2.txt
```

---

### 25. Go to `Dir2` and remove the subdirectory `Dir3`

```bash
cd ~/main/Dir1/Dir2
rmdir Dir3
```

*(Make sure `Dir3` is empty before using `rmdir`.)*

---

### 26. From your home folder, remove `Dir2`

```bash
cd ~
rmdir ~/main/Dir1/Dir2
```

*(Again, `Dir2` must be empty.)*

---

## 5. Viewing Parts of a File with `head`, `tail` & `tac`

These exercises use the file `countfinal.txt`.

### 27. Display the **first 10 lines** of `countfinal`

```bash
head countfinal.txt
```

---

### 28. Display the **last 10 lines** of `countfinal`

```bash
tail countfinal.txt
```

---

### 29. Display the **first 5 lines** of `countfinal`

```bash
head -n 5 countfinal.txt
```

---

### 30. Display the **last 4 lines** of `countfinal`

```bash
tail -n 4 countfinal.txt
```

---

### 31. Display the contents of `countfinal` in **reverse order** (last line first)

```bash
tac countfinal.txt
```

---

## 6. Manual Pages & Command Help

### View the manual page for `ls`

```bash
man ls
```

---

### Use `whatis` to see a one-line description of commands

```bash
whatis man
whatis pwd
```

---

## 7. Basic Navigation Commands (Recap)

```bash
# Go to home directory
cd ~

# Go one level up
cd ..

# List files in current directory
ls

# Long listing with permissions, size, etc.
ls -l
```

---

## 8. Directory Management Commands

### Create a directory

```bash
mkdir testdir
```

---

### Create nested directories in a single command

```bash
mkdir -p GrantParent/Parent/Child
```

---

### Remove an **empty** directory

```bash
rmdir testdir
```

---

### Remove a directory tree recursively (be careful!)

```bash
rm -r GrantParent
```

---

### Check the type of a file

```bash
file main.txt
```

---

## 9. File Management Commands

### Create an empty file with `touch`

```bash
touch main.txt
```

---

### Copy a file

```bash
cp main.txt main2.txt
```

---

### Copy a directory recursively

```bash
cp -r GrantParent/ house/
```

---

### Rename or move a file

```bash
mv main.txt main_renamed.txt

# Move a file into another directory
mv main_renamed.txt GrantParent/
```

---

## 10. Viewing Files: `head`, `tail`, `cat`

Assume we have `fn.txt` with numbers:

```bash
cat > fn.txt << 'EOF'
one
two
three
four
five
six
seven
eight
nine
ten
EOF
```

### Show the first lines with `head`

```bash
head fn.txt
```

### Show the last lines with `tail`

```bash
tail fn.txt
```

### Show the entire file with `cat`

```bash
cat fn.txt
```

---

## 11. Creating Files with `cat` & Custom End Marker

You can use `cat` with a **custom end marker**:

```bash
cat > fn.txt << eof
one
two
three
eof
```

Here, typing `eof` on a new line finishes the input.

---

## 12. Concatenating Files

Combine multiple files into one:

```bash
cat fn.txt main2.txt > hero.txt
```

This creates `hero.txt` containing `fn.txt` followed by `main2.txt`.

---

## 13. Reversing Output

To print a file in reverse line order:

```bash
tac fn.txt
```

To reverse a concatenated file:

```bash
cat fn.txt main2.txt > hero.txt
tac hero.txt
```

---

