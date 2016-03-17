#!/bin/sh

JAVA_HOME="/usr/lib/jvm/java-1.6.0-openjdk-1.6.0.0.x86_64"
AGENT_HOME=".."
LAF_HOME="$AGENT_HOME/env"

CLASSPATH=$AGENT_HOME/lib/lafj_II_2006.jar
CLASSPATH=$CLASSPATH:$AGENT_HOME/lib/lafw_2006.jar
CLASSPATH=$CLASSPATH:$AGENT_HOME/lib/jaxrpc.jar
CLASSPATH=$CLASSPATH:$AGENT_HOME/lib/axis.jar
CLASSPATH=$CLASSPATH:$AGENT_HOME/lib/commons-discovery-0.2.jar
CLASSPATH=$CLASSPATH:$AGENT_HOME/lib/commons-logging-1.0.4.jar
CLASSPATH=$CLASSPATH:$AGENT_HOME/lib/activation.jar
CLASSPATH=$CLASSPATH:$AGENT_HOME/lib/j2ee.jar
CLASSPATH=$CLASSPATH:$AGENT_HOME/lib/mail.jar
CLASSPATH=$CLASSPATH:$AGENT_HOME/lib/wsdl4j-1.5.1.jar
CLASSPATH=$CLASSPATH:$AGENT_HOME/lib/jazzlib_0.07.jar
CLASSPATH=$CLASSPATH:$AGENT_HOME/lib/ojdbc14.jar
CLASSPATH=$CLASSPATH:$AGENT_HOME/lib/postnet_agent.jar
CLASSPATH=$CLASSPATH:$AGENT_HOME/lib/sqljdbc.jar
CLASSPATH=$CLASSPATH:$AGENT_HOME/lib/postnet_agent_stub.jar

MAIN_CLASS="soaway.agent.event.LManualInvoker"

$JAVA_HOME/bin/java -cp $CLASSPATH -Dlaf.home=$LAF_HOME -Xms512m -Xmx512m -Dhttp.proxyHost=127.0.0.1 -Dhttp.proxyPort=8888 $MAIN_CLASS biz deliveryResult.rcv
