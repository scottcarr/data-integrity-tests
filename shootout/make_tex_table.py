from subprocess import Popen, PIPE

def getUserTime(txt):
    parts = txt.split()
    user = parts[0]
    number = user.rstrip("user")
    return float(number)

benchmarks = ["binarytrees", "fasta", "nbody"]

n_trees = 15

args = ["time", "./binarytrees", str(n_trees)]
p = Popen(args, stderr=PIPE)
txt =  p.communicate()[1]
bt_orig = getUserTime(txt)

args = ["time", "./binarytrees_dci", str(n_trees)]
p = Popen(args, stderr=PIPE)
txt =  p.communicate()[1]
bt_dci = getUserTime(txt)

args = ["time", "./binarytrees_soft", str(n_trees)]
p = Popen(args, stderr=PIPE)
txt =  p.communicate()[1]
bt_soft = getUserTime(txt)

n_fasta = "1000000"
args = ["time", "./fasta", n_fasta]
p = Popen(args, stderr=PIPE)
txt =  p.communicate()[1]
f_orig = getUserTime(txt)

args = ["time", "./fasta_dci", n_fasta]
p = Popen(args, stderr=PIPE)
txt =  p.communicate()[1]
f_dci = getUserTime(txt)

# does not work
#args = ["time", "./fasta_soft", n_fasta]
#p = Popen(args, stderr=PIPE)
#txt =  p.communicate()[1]
#f_soft = getUserTime(txt)

n_nbody = "1000000"
args = ["time", "./nbody", n_nbody]
p = Popen(args, stderr=PIPE)
txt =  p.communicate()[1]
nbody_orig = getUserTime(txt)

args = ["time", "./nbody_dci", n_nbody]
p = Popen(args, stderr=PIPE)
txt =  p.communicate()[1]
nbody_dci = getUserTime(txt)

args = ["time", "./nbody_soft", n_nbody]
p = Popen(args, stderr=PIPE)
txt =  p.communicate()[1]
nbody_soft = getUserTime(txt)

#print bt_orig, bt_dci, f_orig, f_dci, nbody_orig, nbody_dci

bt_ovh_dci = (bt_dci / bt_orig)*100 - 100
bt_ovh_soft = (bt_soft / bt_orig)*100 - 100
f_ovh_dci = (f_dci / f_orig)*100 - 100

nbody_ovh_dci = (nbody_dci / nbody_orig) * 100 - 100
nbody_ovh_soft = (nbody_soft / nbody_orig) * 100 - 100

# does not work
#f_ovh_soft = (f_soft / f_orig)*100 - 100

#print bt_ovh_dci, bt_ovh_soft
#print f_ovh_dci, f_ovh_soft
#print nbody_ovh_dci, nbody_ovh_soft
#f_ovh = f_dci / f_orig
#nbody_ovh = nbody_dci / nbody_orig

#bt_ovh_dci = .7
#f_ovh_dci = .5
#nbody_ovh_dci = .1
#
#bt_ovh_soft = 1.7
f_ovh_soft = "N/A" 
#nbody_ovh_soft = 10.1

#print bt_ovh, f_ovh, nbody_ovh


tbl_txt = """
\\begin{{table}}
\\centering
\\begin{{tabular}}{{l | r | r}}
benchmark & DCI & Softbound+CETS \\\\
\\hline
binarytrees & {0}\% & {1}\% \\\\
fasta & {2}\% & {3} \\\\
nbody & {4}\% &  {5}\% \\\\
\end{{tabular}}
\caption{{Performance overhead on Computer Language Benchmarks Game}}
\label{{tbl:micro}}
\end{{table}}
"""

print tbl_txt.format(bt_ovh_dci, bt_ovh_soft, f_ovh_dci, f_ovh_soft, nbody_ovh_dci, nbody_ovh_soft)
