/**
 * Created by Илья Сиганов on 03.06.2018.
 */

#include <Log/logging.h>
#include <log4cxx/fileappender.h>
#include <patternlayout.h>

log4cxx::AppenderPtr syslogAppender() {
  log4cxx::PatternLayoutPtr pattern = new log4cxx::PatternLayout("%d [%t] %-5p %c - %m%n");
  log4cxx::FileAppenderPtr appender = new log4cxx::FileAppender(pattern, "/tmp/game.log");
  log4cxx::helpers::Pool p;
  appender->activateOptions(p);
  return log4cxx::AppenderPtr(appender);
}