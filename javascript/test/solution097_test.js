var assert = require('assert');
var solution097 = require('../src/euler/solution097');

describe('Solution097', function() {
  describe('answer', function() {
    it('will answer problem 097', function() {
      assert.equal(solution097.answer(), 8739992577);
    });
  });
});