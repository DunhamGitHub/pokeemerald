# Instructions

## Linux

Parallels, download Ubuntu (currently ubuntu-24.04.3-desktop-amd64 LTS)

...
Open Terminal and enter the following commands, depending on which distro you're using.

### Debian/Ubuntu-based distributions
Run the following command to install the necessary packages:
```bash
sudo apt install build-essential binutils-arm-none-eabi git libpng-dev
```

Install agbcc into pokeemerald. The commands to run depend on certain conditions. **You should only follow one of the listed instructions**:
- If agbcc has **not been built before** in the folder where you chose to store pokeemerald, run the following commands to build and install it into pokeemerald:

    ```bash
    git clone https://github.com/pret/agbcc
    cd agbcc
    ./build.sh
    ./install.sh ../pokeemerald
    ```

- **Otherwise**, if agbcc has been built before on the same terminal, run the following commands to install agbcc into pokeemerald:

    ```bash
    cd agbcc
    ./install.sh ../pokeemerald
    ```

    <details>
        <summary><i>Note...</i></summary>

        > If building agbcc or pokeemerald results in an error, try deleting the agbcc folder and re-installing agbcc as if it has not been built before.
    </details>

3. Once agbcc is installed, change directory back to the base directory where pokeemerald and agbcc are stored:

    ```bash
    cd ..
    ```

Now you're ready to [build **pokeemerald**](#build-pokeemerald)
## Build pokeemerald
If you aren't in the pokeemerald directory already, then **change directory** to the pokeemerald folder:
```bash
cd pokeemerald
```
To build **pokeemerald.gba** (Note: to speed up builds, see [Parallel builds](#parallel-builds)):
```bash
make
```
If it has built successfully you will have the output file **pokeemerald.gba** in your project folder.
