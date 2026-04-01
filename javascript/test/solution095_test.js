var assert = require('assert');
var solution095 = require('../src/euler/solution095');

describe('Solution095', function() {
  describe('answer', function() {
    it('will answer problem 095', function() {
      assert.equal(solution095.answer(), 14316);
    });
  });
});