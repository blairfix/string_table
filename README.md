# string_table

`string_table` is an R function for making a table of values for a vector of strings (characters).


### Inputs

```R
string_table(x)
```

* `x` = a character vector that you want to tabulate 

### Output
`string_table` returns a named vector with the number of counts for each element in `x`.


### Example

`string_table` does the same thing as the R base function `table`. But it does it faster. An example:


```R
library(Rcpp)

sourceCpp("string_table.cpp")

# a character vector
x = c("go", "go", "far", "test")

# table of values
my_table = string_table(x)
```

The result is:

```R
> my_table
 far   go test 
   1    2    1 
```

The speed difference becomes apparent for large vectors:

```R
# make large character vector
x = stringi::stri_rand_strings(10^6, 3)

# benchmark
microbenchmark::microbenchmark(
  string_tab = string_table(x),
  base_tab = table(x),
  times = 5
)
```

`string_table` is between 5 to 10 times faster than base R:

```R
Unit: milliseconds
       expr       min        lq      mean    median        uq       max neval
 string_tab  241.4719  241.9425  258.5144  246.8945  249.1548  313.1084     5
   base_tab 1504.3363 1507.9075 1513.4096 1508.7786 1518.6787 1527.3470     5
```

### Installation

To use `string_table`, install the following R packages:
 * [Rcpp](https://cran.r-string_replace.org/web/packages/Rcpp/index.html) 
 * [BH](https://cran.r-project.org/web/packages/BH/index.html)

Put the source code (`string_table.cpp`) in the directory of your R script. Then source it with the command `sourceCpp('string_table.cpp')`.



