require 'fileutils'

task :default => [:build]

IN_DIR  = 'input'
OUT_DIR = 'pdf'
BUILD_DIR = 'build'

PDFLATEX_BIN = %x{which pdflatex}.chomp

task :build => [:clean, :compile, :publish]

task :clean do
  FileUtils.rm_r Dir["#{BUILD_DIR}/*"]
end

task :compile do
  FileUtils.mkdir BUILD_DIR if !Dir.exists?(BUILD_DIR)
  Dir["#{IN_DIR}/**/*.tex"].each do |file|
    sh "#{PDFLATEX_BIN} -output-dir=#{BUILD_DIR} #{file}"
  end
end

task :publish do
  FileUtils.mkdir OUT_DIR if !Dir.exists?(OUT_DIR)
  Dir["#{BUILD_DIR}/**/*.pdf"].each do |pdf|
    FileUtils.mv(pdf, OUT_DIR)
  end
end

task :single, [:file] => :clean do |t,args|
  FileUtils.mkdir BUILD_DIR if !Dir.exists?(BUILD_DIR)
  Dir["#{IN_DIR}/**/#{args[:file]}.tex"].each do |file|
    sh "#{PDFLATEX_BIN} -output-dir=#{BUILD_DIR} #{file}"
  end
  Rake::Task[:publish].invoke
end

task :onsnapci do
  fail "Only run on Snap-CI" unless ENV['SNAP_CI'] == 'true'
end

task :download => :onsnapci do
  sh "rsync -a --delete rsync://ctan.math.utah.edu/CTAN/systems/texlive/tlnet/ #{ENV['SNAP_CACHE_DIR']}/texlive"
end
