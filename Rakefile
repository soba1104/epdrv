APP = "epdrv"

verbose(false)

task :default => :start

task :start do
  sh "erl -pz ebin -eval '{ok, _} = application:ensure_all_started(#{APP}).'"
end
